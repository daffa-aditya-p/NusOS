#!/usr/bin/env python3
"""
NusOS OTP Email System
Sistem pengiriman OTP untuk reset password NusOS
"""

import smtplib
import sys
import random
import time
from email.message import EmailMessage

def generate_otp():
    """Generate 6-digit OTP code"""
    return str(random.randint(100000, 999999))

def send_otp(to_email, otp_code):
    """
    Kirim OTP ke email menggunakan SMTP
    """
    try:
        # Setup email message
        msg = EmailMessage()
        msg['Subject'] = '🔐 Kode OTP NusOS - Password Reset'
        msg['From'] = 'daffaaditya@daffadev.my.id'
        msg['To'] = to_email
        
        # Email content dalam HTML
        email_content = f"""
        <html>
        <body style="font-family: Arial, sans-serif; background-color: #f4f4f4; padding: 20px;">
            <div style="max-width: 600px; margin: 0 auto; background-color: white; padding: 30px; border-radius: 10px; box-shadow: 0 4px 6px rgba(0,0,0,0.1);">
                <div style="text-align: center; margin-bottom: 30px;">
                    <h1 style="color: #2c3e50; margin: 0;">🚀 NusOS</h1>
                    <p style="color: #7f8c8d; margin: 5px 0;">World's Best Operating System</p>
                </div>
                
                <div style="background-color: #ecf0f1; padding: 20px; border-radius: 8px; margin: 20px 0;">
                    <h2 style="color: #34495e; text-align: center; margin: 0 0 15px 0;">🔐 Kode Verifikasi OTP</h2>
                    <div style="text-align: center;">
                        <span style="font-size: 32px; font-weight: bold; color: #e74c3c; letter-spacing: 8px; background-color: white; padding: 15px 25px; border-radius: 5px; display: inline-block; border: 2px dashed #e74c3c;">
                            {otp_code}
                        </span>
                    </div>
                </div>
                
                <div style="margin: 20px 0;">
                    <p style="color: #2c3e50; line-height: 1.6;">
                        <strong>Halo Pengguna NusOS!</strong><br><br>
                        Anda telah meminta reset password untuk akun NusOS Anda. 
                        Gunakan kode OTP di atas untuk melanjutkan proses reset password.
                    </p>
                    
                    <div style="background-color: #fff3cd; border: 1px solid #ffeaa7; padding: 15px; border-radius: 5px; margin: 15px 0;">
                        <p style="margin: 0; color: #856404;">
                            ⚠️ <strong>Penting:</strong><br>
                            • Kode ini berlaku selama 10 menit<br>
                            • Jangan berikan kode ini kepada siapa pun<br>
                            • Jika Anda tidak meminta reset password, abaikan email ini
                        </p>
                    </div>
                </div>
                
                <div style="text-align: center; margin-top: 30px; padding-top: 20px; border-top: 1px solid #ecf0f1;">
                    <p style="color: #7f8c8d; font-size: 14px; margin: 0;">
                        Email ini dikirim secara otomatis oleh sistem NusOS<br>
                        © 2025 NusOS - Sistem Operasi Terbaik Dunia
                    </p>
                </div>
            </div>
        </body>
        </html>
        """
        
        msg.set_content(email_content, subtype='html')
        
        # SMTP Configuration
        smtp_server = 'smtp.gmail.com'
        smtp_port = 587
        smtp_user = 'daffaaditya0407@gmail.com'
        smtp_pass = 'rdxz zihs gbnv grcm'  # App password Gmail
        
        # Send email
        print("📧 Menghubungkan ke server email...")
        with smtplib.SMTP(smtp_server, smtp_port) as smtp:
            smtp.starttls()
            print("🔐 Melakukan autentikasi...")
            smtp.login(smtp_user, smtp_pass)
            print(f"📤 Mengirim OTP ke {to_email}...")
            smtp.send_message(msg)
            
        print("✅ OTP berhasil dikirim!")
        print(f"🔑 Kode OTP: {otp_code}")
        print("📱 Silakan cek email Anda dan masukkan kode OTP.")
        
        # Save OTP to temporary file for verification
        with open('./database/temp_otp.txt', 'w') as f:
            f.write(f"{otp_code}\\n{int(time.time())}")
        
        return True
        
    except smtplib.SMTPAuthenticationError:
        print("❌ Gagal autentikasi email! Periksa konfigurasi SMTP.")
        return False
    except smtplib.SMTPRecipientsRefused:
        print("❌ Email tujuan tidak valid atau ditolak!")
        return False
    except smtplib.SMTPException as e:
        print(f"❌ Error SMTP: {e}")
        return False
    except Exception as e:
        print(f"❌ Error tidak terduga: {e}")
        return False

def verify_otp(input_otp):
    """
    Verifikasi OTP yang dimasukkan user
    """
    try:
        with open('./database/temp_otp.txt', 'r') as f:
            lines = f.read().strip().split('\\n')
            stored_otp = lines[0]
            timestamp = int(lines[1])
        
        # Check if OTP is expired (10 minutes = 600 seconds)
        current_time = int(time.time())
        if current_time - timestamp > 600:
            print("❌ Kode OTP sudah kedaluwarsa! Silakan minta kode baru.")
            return False
        
        if input_otp == stored_otp:
            # Delete temporary OTP file
            import os
            os.remove('./database/temp_otp.txt')
            print("✅ Kode OTP valid!")
            return True
        else:
            print("❌ Kode OTP tidak valid!")
            return False
            
    except FileNotFoundError:
        print("❌ Tidak ada kode OTP yang tersimpan!")
        return False
    except Exception as e:
        print(f"❌ Error verifikasi OTP: {e}")
        return False

def main():
    """
    Main function untuk handle command line arguments
    """
    if len(sys.argv) < 2:
        print("❌ Usage: python3 send_otp.py <email>")
        print("   atau: python3 send_otp.py verify <otp_code>")
        sys.exit(1)
    
    if sys.argv[1] == "verify":
        if len(sys.argv) < 3:
            print("❌ Usage: python3 send_otp.py verify <otp_code>")
            sys.exit(1)
        
        otp_input = sys.argv[2]
        if verify_otp(otp_input):
            sys.exit(0)  # Success
        else:
            sys.exit(1)  # Failed
    else:
        email = sys.argv[1]
        
        # Validate basic email format
        if '@' not in email or '.' not in email:
            print("❌ Format email tidak valid!")
            sys.exit(1)
        
        print("🚀 === SISTEM OTP NUSOS === 🚀")
        print("💫 Generating secure OTP code...")
        
        otp = generate_otp()
        
        if send_otp(email, otp):
            print("\\n🎉 Proses pengiriman OTP selesai!")
            print("📩 Cek kotak masuk email Anda.")
            sys.exit(0)
        else:
            print("\\n💔 Gagal mengirim OTP!")
            sys.exit(1)

if __name__ == "__main__":
    main()
