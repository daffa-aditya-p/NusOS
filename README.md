# 🚀 NusOS - World's Best Operating System

<div align="center">

```
███╗   ██╗██╗   ██╗███████╗ ██████╗ ███████╗
████╗  ██║██║   ██║██╔════╝██╔═══██╗██╔════╝
██╔██╗ ██║██║   ██║███████╗██║   ██║███████╗
██║╚██╗██║██║   ██║╚════██║██║   ██║╚════██║
██║ ╚████║╚██████╔╝███████║╚██████╔╝███████║
╚═╝  ╚═══╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚══════╝
```

**🌟 Sistem Operasi Terbaik, Tercepat, Teringan, dan Teraman di Dunia! 🌟**

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![Language](https://img.shields.io/badge/language-C-brightgreen)
![Platform](https://img.shields.io/badge/platform-Linux-orange)
![License](https://img.shields.io/badge/license-MIT-green)

</div>

## ✨ Fitur Utama

### 🔥 **Teknologi Canggih 2025**
- **Pemrosesan Data Paralel** - Tidak ada lagi waiting time!
- **Optimasi Super Advanced** - Lebih cepat dari Linux, Windows, dan Termux
- **Keamanan Tingkat Militer** - Sistem teraman di dunia
- **Multi-language Support** - Indonesia & English

### 🎨 **Kustomisasi Tak Terbatas**
- **8 Tema Premium** - Dark Blue, Green Matrix, Purple Night, dan lainnya
- **7 Warna Terminal** - Sesuaikan dengan selera Anda
- **3 Mode CLI** - CMD, Terminal, atau gabungan keduanya
- **Multi-timezone** - Support zona waktu global

### 🛠️ **CLI Super Powerful**
- **Universal Commands** - Support CMD, Linux Terminal, dan Termux
- **Package Manager** - `apt`, `pkg`, `sudo` semua bisa!
- **Real-time Processing** - Eksekusi perintah secara paralel
- **Smart Auto-completion** - Produktivitas maksimal

### 🔐 **Sistem Keamanan Advanced**
- **Email OTP Authentication** - Reset password via email
- **Encrypted User Data** - Data tersimpan dengan aman
- **Session Management** - Kontrol akses yang ketat

## 🚀 Quick Start

### 1. **Persiapan Sistem**
```bash
# Clone repository
git clone https://github.com/daffa-aditya-p/NusOS.git
cd NusOS

# Install dependencies
make install-deps
```

### 2. **Build & Run**
```bash
# Build NusOS
make

# Jalankan NusOS
make run
```

### 3. **Setup Pertama Kali**
1. Pilih bahasa (Indonesia/English)
2. Isi data diri (nama, username, password, email)
3. Pilih storage, zona waktu, dan tema
4. Konfigurasi CLI mode dan warna terminal
5. Selesai! 🎉

## 📖 Panduan Penggunaan

### **Login System**
```
Username: [username_anda]
Password: [password_anda]
```

Lupa password? Ketik `forgot` untuk reset via email OTP!

### **CLI Commands**

#### 📁 **File & Directory**
```bash
ls / dir              # List files dan folder
cd [path]             # Pindah direktori
mkdir [nama]          # Buat folder baru
pwd                   # Lihat direktori saat ini
rm [file]             # Hapus file
cp [src] [dest]       # Copy file
mv [src] [dest]       # Move/rename file
```

#### 🔧 **System Commands**
```bash
ps                    # Lihat proses running
top                   # Monitor sistem real-time
free                  # Memory usage
df                    # Disk usage
clear                 # Bersihkan layar
```

#### 📦 **Package Management**
```bash
apt install [package] # Install package (Linux style)
pkg install [package] # Install package (Termux style)
sudo [command]        # Run sebagai administrator
```

#### ⚙️ **NusOS Specific**
```bash
settings              # Buka pengaturan NusOS
theme [nama]          # Ganti tema
logout                # Keluar dari sistem
shutdown              # Matikan NusOS
help                  # Bantuan lengkap
```

## ⚙️ Pengaturan (Settings)

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
- [ ] Network management
- [ ] Advanced file encryption
- [ ] Plugin system

### **Version 2.0** (Future)
- [ ] Real kernel implementation
- [ ] Hardware abstraction layer
- [ ] Device drivers
- [ ] Multi-user support

## 🔧 Persyaratan Sistem

### **Minimum Requirements**
- OS: Linux/Unix-based system
- Compiler: GCC 4.8+
- Python: 3.6+
- Memory: 512MB RAM
- Storage: 100MB free space

### **Recommended**
- OS: Ubuntu 20.04+ / Debian 10+
- Compiler: GCC 9.0+
- Python: 3.8+
- Memory: 2GB RAM
- Storage: 1GB free space

## 🤝 Kontribusi

Kami welcome kontribusi dari developer manapun!

1. Fork repository
2. Buat feature branch
3. Commit perubahan
4. Push ke branch
5. Buat Pull Request

## 📄 License

Distributed under the MIT License. See `LICENSE` for more information.

## 👨‍💻 Developer

**Daffa Aditya Permana**
- GitHub: [@daffa-aditya-p](https://github.com/daffa-aditya-p)
- Email: daffaaditya@daffadev.my.id

## 🙏 Acknowledgments

- Terinspirasi dari Linux, Windows, dan Termux
- Thanks to semua teman-teman yang akan menggunakan NusOS
- Special thanks to komunitas open source

---

<div align="center">

**🌟 NusOS - Sistem Operasi Terbaik Dunia 2025! 🌟**

*Dibuat dengan ❤️ untuk masa depan computing yang lebih baik*

</div>
