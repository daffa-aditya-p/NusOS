# NusOS Makefile
# Sistem Operasi Terbaik Dunia - Build System

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
INCLUDES = -Iinclude
SRCDIR = src
BUILDDIR = build
TARGET = nusos

# Source files
SOURCES = $(SRCDIR)/main.c \
          $(SRCDIR)/config/setup.c \
          $(SRCDIR)/config/settings.c \
          $(SRCDIR)/auth/login.c \
          $(SRCDIR)/cli/main_cli.c \
          $(SRCDIR)/kernel/kernel.c

# Object files
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

# Default target
all: setup $(TARGET)

# Create build directories
setup:
	@echo "🚀 Setting up NusOS build environment..."
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BUILDDIR)/config
	@mkdir -p $(BUILDDIR)/auth
	@mkdir -p $(BUILDDIR)/cli
	@mkdir -p $(BUILDDIR)/kernel
	@mkdir -p $(BUILDDIR)/boot
	@mkdir -p database
	@mkdir -p database/config
	@mkdir -p database/users
	@echo "✅ Build directories created!"

# Build main target
$(TARGET): $(OBJECTS)
	@echo "🔗 Linking NusOS..."
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "✅ NusOS built successfully!"
	@echo "🎉 World's Best Operating System is ready!"

# Compile source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@echo "🔨 Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Install Python dependencies
install-deps:
	@echo "📦 Installing Python dependencies for OTP system..."
	@python3 -m pip install --upgrade pip
	@chmod +x scripts/send_otp.py
	@echo "✅ Dependencies installed!"

# Clean build files
clean:
	@echo "🧹 Cleaning build files..."
	@rm -rf $(BUILDDIR)
	@rm -f $(TARGET)
	@echo "✅ Clean completed!"

# Clean all including database
clean-all: clean
	@echo "🗑️ Cleaning all data including database..."
	@rm -rf database
	@echo "⚠️ All user data has been removed!"

# Run NusOS
run: $(TARGET)
	@echo "🚀 Starting NusOS - World's Best Operating System..."
	@./$(TARGET)

# Debug mode
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)
	@echo "🐛 NusOS built in debug mode"

# Release mode
release: CFLAGS += -DRELEASE
release: clean $(TARGET)
	@echo "📦 NusOS built for release"

# Test OTP system
test-otp:
	@echo "📧 Testing OTP system..."
	@python3 scripts/send_otp.py test@example.com

# Install NusOS system-wide (requires sudo)
install: $(TARGET)
	@echo "📥 Installing NusOS system-wide..."
	@sudo cp $(TARGET) /usr/local/bin/
	@sudo chmod +x /usr/local/bin/$(TARGET)
	@sudo mkdir -p /etc/nusos
	@sudo cp -r scripts /etc/nusos/
	@echo "✅ NusOS installed! Run 'nusos' from anywhere."

# Uninstall NusOS
uninstall:
	@echo "📤 Uninstalling NusOS..."
	@sudo rm -f /usr/local/bin/$(TARGET)
	@sudo rm -rf /etc/nusos
	@echo "✅ NusOS uninstalled!"

# Show system info
info:
	@echo "🌟 === NusOS Build Information === 🌟"
	@echo "Compiler: $(CC)"
	@echo "Flags: $(CFLAGS)"
	@echo "Target: $(TARGET)"
	@echo "Sources: $(words $(SOURCES)) files"
	@echo "Python: $(shell python3 --version 2>/dev/null || echo 'Not found')"
	@echo "Build Date: $(shell date)"
	@echo "💫 World's Best Operating System 💫"

# Help
help:
	@echo "🚀 === NusOS Build System Help === 🚀"
	@echo ""
	@echo "Available targets:"
	@echo "  all          - Build NusOS (default)"
	@echo "  clean        - Clean build files"
	@echo "  clean-all    - Clean everything including database"
	@echo "  run          - Build and run NusOS"
	@echo "  debug        - Build in debug mode"
	@echo "  release      - Build for release"
	@echo "  install-deps - Install Python dependencies"
	@echo "  test-otp     - Test OTP email system"
	@echo "  install      - Install NusOS system-wide"
	@echo "  uninstall    - Uninstall NusOS"
	@echo "  info         - Show build information"
	@echo "  help         - Show this help"
	@echo ""
	@echo "Quick start:"
	@echo "  make install-deps  # Install dependencies"
	@echo "  make run           # Build and run NusOS"
	@echo ""
	@echo "🌟 Welcome to NusOS - World's Best Operating System! 🌟"

# Phony targets
.PHONY: all setup clean clean-all run debug release install-deps test-otp install uninstall info help
