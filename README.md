# 🚀 NusOS v1.1 - World's Best Operating System

<div align="center">

```
███╗   ██╗██╗   ██╗███████╗ ██████╗ ███████╗
████╗  ██║██║   ██║██╔════╝██╔═══██╗██╔════╝
██╔██╗ ██║██║   ██║███████╗██║   ██║███████╗
██║╚██╗██║██║   ██║╚════██║██║   ██║╚════██║
██║ ╚████║╚██████╔╝███████║╚██████╔╝███████║
╚═╝  ╚═══╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚══════╝
```

**💫 The Fastest, Lightest, and Most Secure Operating System of 2025! 💫**

![Version](https://img.shields.io/badge/version-1.1-blue)
![Language](https://img.shields.io/badge/language-C-brightgreen)
![Platform](https://img.shields.io/badge/platform-Linux-orange)
![License](https://img.shields.io/badge/license-MIT-green)
![Build](https://img.shields.io/badge/build-passing-success)

</div>

---

## ✨ New in v1.1 - Major Update!

🎉 **COMPLETE MULTI-USER OPERATING SYSTEM**

### 🔥 **Revolutionary Features 2025**
- **🔐 Multi-User Authentication** - Username uniqueness & secure login
- **📧 Email Password Reset** - OTP verification system  
- **🎨 Military-Grade UI** - Beautiful ASCII borders & professional styling
- **👥 User Management** - Complete user administration system
- **⚡ Smart Performance** - Intelligent input handling & optimization
- **🛡️ Enhanced Security** - Session management & data protection

### 🎨 **Ultimate Customization**
- **8 Premium Themes** - Dark Blue, Green Matrix, Purple Night, dan lainnya
- **7 Terminal Colors** - Sesuaikan dengan selera Anda
- **3 CLI Modes** - CMD, Terminal, atau gabungan keduanya
- **Multi-timezone** - Support zona waktu global

### 🛠️ **Super Powerful CLI**
- **100+ Commands** - Support Linux, CMD, dan Termux
- **Package Managers** - `apt`, `pkg`, `pip`, `npm`, `sudo` semua bisa!
- **Real-time Processing** - Eksekusi perintah secara paralel
- **Smart Auto-completion** - Produktivitas maksimal
- **Auto-fallback** - Intelligent command alternatives

### 🔐 **Military-Grade Security**
- **Email OTP Authentication** - Reset password via email dengan kode 6 digit
- **Encrypted User Data** - Data tersimpan dengan aman
- **Session Management** - Kontrol akses yang ketat
- **Input Validation** - Protection against injection attacks

## 🚀 Quick Start

### 1. **Clone & Build**
```bash
# Clone repository
git clone https://github.com/daffa-aditya-p/NusOS.git
cd NusOS

# Build NusOS (otomatis compile semua dependencies)
make

# Jalankan NusOS
./nusos
```

### 2. **First Time Setup** 
Saat pertama kali menjalankan, Anda akan diminta:

1. **🌍 Language Selection** (Indonesia/English)
2. **👤 User Registration:**
   - Full name 
   - Username (harus unik)
   - Password (aman)
   - Email address (untuk OTP reset password)
   - Storage allocation (GB)
3. **🎨 Personalization:**
   - Theme selection (8 pilihan keren)
   - Timezone configuration
   - CLI mode preference
   - Terminal color scheme

**Selesai! Anda siap menggunakan NusOS v1.1! 🎉**

## 🔐 Login & Security

### **Standard Login**
```
Username: [your_username]
Password: [your_password]
```

### **Lupa Password?**
Ketik `forgot` saat login untuk reset via email:
- ✅ Sistem kirim OTP 6 digit ke email Anda
- ✅ Masukkan kode OTP yang diterima
- ✅ Set password baru
- ✅ Login langsung dengan password baru!

### **Multi-User Support**
```bash
# Lihat semua user terdaftar
list-users

# Ganti user (logout dulu)
logout
```

## 📖 Panduan Penggunaan

## 📖 Command Reference

### **🏠 NusOS Specific Commands**
```bash
help                  # Complete command reference
settings              # Open NusOS configuration panel  
list-users           # Display all registered users (NEW!)
theme [name]         # Change visual theme instantly
logout / exit        # Exit NusOS safely
shutdown             # Shutdown system
reboot               # Restart system
```

### **👤 User Management** 
```bash
# Registration (otomatis saat first-time)
# Username harus unik - sistem cek otomatis!

# Password Management
# Ketik 'forgot' saat login untuk reset via email OTP

# User Information
list-users           # Lihat semua user: nama, username, email
settings             # Edit profil: nama, email, password, dll
```

### **📁 File & Directory Operations**
```bash
ls / dir [path]       # List files dan folder (support -la flags)
cd [path]             # Change directory (support -, .., ~)
mkdir [-p] [name]     # Create directories (-p for recursive)
pwd                   # Show current directory
rm [-rf] [file]       # Remove files/directories  
cp [-r] [src] [dest]  # Copy files (recursive with -r)
mv [src] [dest]       # Move/rename files
cat [file]            # Display file contents
touch [file]          # Create empty file
find [path] [name]    # Find files by name
grep [pattern] [file] # Search text in files
```

### **🔧 System Monitoring**
```bash
ps                    # Show running processes
top                   # Real-time system monitor  
htop                  # Enhanced system monitor
free                  # Memory usage information
df                    # Disk usage information
du [path]             # Directory size
lsblk                 # List block devices
```

### **🌐 Network Commands**
```bash
ping [host]           # Test network connectivity
wget [url]            # Download files from web
curl [url]            # Transfer data from servers  
ssh [user@host]       # Secure Shell remote login
scp [src] [dest]      # Secure copy over SSH
netstat               # Show network connections
ifconfig              # Network interface configuration
```

### **📦 Package Management**
```bash
apt [install|update|remove] [pkg]  # Ubuntu/Debian packages
pkg [install|update|remove] [pkg]  # Termux-style packages  
pip [install|uninstall] [pkg]      # Python packages
npm [install|uninstall] [pkg]      # Node.js packages
sudo [command]                     # Run as administrator
```

### **🛠️ Development Tools**
```bash
gcc [files] -o [output]    # C/C++ compiler
make [target]              # Build automation
python/python3 [file]      # Python interpreter
node [file]                # Node.js runtime
git [commands]             # Version control
```

## 🎨 NusOS in Action

### **🔐 Beautiful Login System**
```
╔════════════════════════════════════════════════╗
║                🔐 USER LOGIN 🔐               ║
╚════════════════════════════════════════════════╝
🌟 Multi-User Support | Military-Grade Security 🌟

👤 Username (default: user): 
🔑 Password: 
```

### **👥 User Management Interface**
```
╔════════════════════════════════════════════════╗
║              👥 REGISTERED USERS 👥           ║
╚════════════════════════════════════════════════╝

🌟 Multi-User System | NusOS v1.1 🌟
──────────────────────────────────────────────────
👤 1. John Doe (@johndoe)
    📧 john@example.com
    ──────────────────────────────────────
👤 2. Jane Smith (@janesmith)  
    📧 jane@example.com
    ──────────────────────────────────────

📊 Total Users: 2
```

### **📧 Email OTP Reset System**
```
╔══════════════════════════════════════════╗
║           🔐 PASSWORD RESET 🔐           ║
╚══════════════════════════════════════════╝

📧 Sending OTP code to email: user@example.com
💻 [████████████████████████████████] 100%
✨ Military-grade security system active...

╔══════════════════════════════════════════╗
║              ✅ OTP SENT ✅              ║
╚══════════════════════════════════════════╝

🔑 Check your email and enter OTP code (6 digits):
```

## 💡 Pro Tips & Best Practices

### **🚀 Performance Tips**
- Use `make clean && make` untuk rebuild optimal
- Jalankan `list-users` untuk monitoring user database
- Gunakan `settings` untuk optimasi personal

### **🔐 Security Best Practices**  
- Selalu gunakan password yang kuat (min 6 karakter)
- Email harus valid untuk fitur OTP reset password
- Username bersifat permanen - pilih dengan bijak!

### **🎨 Customization Hacks**
- Coba semua 8 tema untuk temukan favorit Anda
- Kombinasi CLI mode "both" untuk fleksibilitas maksimal
- Sesuaikan timezone untuk timestamp yang akurat

## ⚙️ Advanced Configuration

Akses dengan perintah `settings` di CLI:

### 👤 **Profil User**
- ✅ Ubah nama lengkap
- ✅ Ubah email
- ✅ Ubah storage
- ❌ Username (permanen untuk keamanan)

### 🎨 **Tampilan**
- **Tema**: 8 pilihan tema premium
- **Warna Terminal**: 7 warna menarik
- **Mode CLI**: CMD, Terminal, atau Both

### 🔧 **Sistem**
- **Bahasa**: Indonesia/English
- **Zona Waktu**: 8 timezone populer
- **Ganti Password**: Sistem keamanan tinggi

### 🗑️ **Reset System**
- **Hapus OS**: Menghapus semua data (HATI-HATI!)

## 🔐 Sistem OTP Email

### **Fitur Email Reset Password**
- Kirim OTP ke email terdaftar
- HTML email template premium
- Kode kedaluwarsa otomatis (10 menit)
- Sistem verifikasi keamanan tinggi

### **Konfigurasi SMTP**
```python
SMTP Server: smtp.gmail.com
Port: 587
From: daffaaditya@daffadev.my.id
```

## 🛠️ Build Commands

```bash
# Basic commands
make                  # Build NusOS
make run             # Build dan jalankan
make clean           # Bersihkan build files

# Advanced commands
make debug           # Build mode debug
make release         # Build mode release
make install         # Install system-wide
make uninstall       # Uninstall dari sistem

# Development
make test-otp        # Test sistem OTP
make info            # Informasi build
make help            # Bantuan lengkap
```

## 📁 Struktur Project

```
NusOS/
├── 📁 src/
│   ├── main.c              # Entry point & boot sequence
│   ├── 📁 auth/
│   │   └── login.c         # Sistem authentication
│   ├── 📁 config/
│   │   ├── setup.c         # Initial setup
│   │   └── settings.c      # Settings management
│   ├── 📁 cli/
│   │   └── main_cli.c      # CLI engine
│   ├── 📁 kernel/          # (Future expansion)
│   └── 📁 boot/            # (Future expansion)
├── 📁 include/
│   └── nusos.h             # Header files
├── 📁 scripts/
│   └── send_otp.py         # OTP email system
├── 📁 database/
│   ├── 📁 config/          # System config
│   └── 📁 users/           # User data
├── Makefile                # Build system
└── README.md               # Dokumentasi
```

## 🎯 Roadmap

### **Version 1.1** (Coming Soon)
- [ ] GUI Mode support
### **Version 1.2** (Next Release)
- [ ] Advanced plugin system
- [ ] Real-time collaboration features  
- [ ] Enhanced encryption algorithms
- [ ] GUI mode support
- [ ] Cloud synchronization

### **Version 2.0** (Future Vision)
- [ ] Real kernel implementation
- [ ] Hardware abstraction layer
- [ ] Device drivers
- [ ] Network protocols
- [ ] Mobile companion app

## � System Requirements

### **Minimum Requirements**
- **OS:** Linux/Unix-based system (Ubuntu 18.04+)
- **Compiler:** GCC 4.8+ with C99 support
- **Python:** 3.6+ (for OTP email system)
- **Memory:** 512MB RAM
- **Storage:** 100MB free space

### **Recommended for Best Performance**
- **OS:** Ubuntu 20.04+ / Debian 10+
- **Compiler:** GCC 9.0+ 
- **Python:** 3.8+
- **Memory:** 2GB RAM
- **Storage:** 1GB free space

## 🤝 Contributing & Community

Kami welcome kontribusi dari developer manapun! 

### **How to Contribute:**
1. 🍴 Fork repository ini
2. 🔄 Buat feature branch (`git checkout -b feature/AmazingFeature`)
3. 💾 Commit changes (`git commit -m 'Add AmazingFeature'`)  
4. 📤 Push to branch (`git push origin feature/AmazingFeature`)
5. 🔀 Open Pull Request

### **Contribution Guidelines:**
- Follow existing code style
- Add comprehensive comments
- Test thoroughly before submitting
- Update documentation if needed

## 📄 License & Legal

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

**Open Source & Free Forever!** 🆓

## 👨‍💻 Creator & Maintainer

**Daffa Aditya Permana**
- 🐙 GitHub: [@daffa-aditya-p](https://github.com/daffa-aditya-p)
- 📧 Email: daffaaditya@daffadev.my.id
- 🌐 Website: [daffadev.my.id](https://daffadev.my.id)

## 🙏 Acknowledgments & Thanks

- 🙏 Inspired by Linux, Windows, dan Termux
- 💝 Thanks to semua yang akan menggunakan NusOS
- 🌟 Special thanks to open source community
- 🚀 Built with passion for the future of computing

---

<div align="center">

**🌟 NusOS v1.1 - The Future of Operating Systems! 🌟**

*Made with ❤️ for a better computing experience*

**⭐ Don't forget to star this repository if you like it! ⭐**

[![GitHub stars](https://img.shields.io/github/stars/daffa-aditya-p/NusOS?style=social)](https://github.com/daffa-aditya-p/NusOS)
[![GitHub forks](https://img.shields.io/github/forks/daffa-aditya-p/NusOS?style=social)](https://github.com/daffa-aditya-p/NusOS)

### 🚀 Ready to Experience the Future? 

```bash
git clone https://github.com/daffa-aditya-p/NusOS.git
cd NusOS && make && ./nusos
```

**Welcome to the World's Best Operating System! 💫**

</div>
