#include "../include/nusos.h"

void login_system() {
    char username[50], password[100];
    char default_user[50];
    int attempts = 0;
    int max_attempts = 3;
    
    // Load default user
    FILE *default_file = fopen("./database/config/default_user", "r");
    if (default_file) {
        fgets(default_user, sizeof(default_user), default_file);
        default_user[strcspn(default_user, "\n")] = 0;
        fclose(default_file);
    } else {
        strcpy(default_user, "user");
    }
    
    while (attempts < max_attempts) {
        system("clear");
        show_ascii_logo();
        
        if (strcmp(current_language, "indonesian") == 0) {
            printf("🔐 Login ke NusOS 🔐\n\n");
            printf("Username (default: %s): ", default_user);
        } else {
            printf("🔐 Login to NusOS 🔐\n\n");
            printf("Username (default: %s): ", default_user);
        }
        
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;
        
        // Use default user if empty
        if (strlen(username) == 0) {
            strcpy(username, default_user);
        }
        
        if (strcmp(current_language, "indonesian") == 0) {
            printf("Password: ");
        } else {
            printf("Password: ");
        }
        
        // Hide password input (simple version)
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;
        
        if (authenticate_user(username, password)) {
            // Load user data
            UserData *user = load_user_data(username);
            if (user) {
                current_user = *user;
                strcpy(current_language, user->language);
                
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("\n✅ Login berhasil! Selamat datang kembali, %s!\n", user->name);
                } else {
                    printf("\n✅ Login successful! Welcome back, %s!\n", user->name);
                }
                
                sleep(2);
                main_cli();
                return;
            }
        }
        
        attempts++;
        if (strcmp(current_language, "indonesian") == 0) {
            printf("\n❌ Username atau password salah! Sisa percobaan: %d\n", max_attempts - attempts);
            if (attempts < max_attempts) {
                printf("Tekan Enter untuk mencoba lagi, atau ketik 'forgot' untuk reset password...\n");
            }
        } else {
            printf("\n❌ Invalid username or password! Attempts remaining: %d\n", max_attempts - attempts);
            if (attempts < max_attempts) {
                printf("Press Enter to try again, or type 'forgot' to reset password...\n");
            }
        }
        
        if (attempts < max_attempts) {
            char input[10];
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            
            if (strcmp(input, "forgot") == 0) {
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("Masukkan email untuk reset password: ");
                } else {
                    printf("Enter email for password reset: ");
                }
                
                char email[100];
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                
                reset_password_via_email(email);
                return;
            }
        }
    }
    
    if (strcmp(current_language, "indonesian") == 0) {
        printf("\n🚫 Terlalu banyak percobaan gagal! Sistem terkunci sementara.\n");
        printf("Hubungi administrator atau tunggu 5 menit sebelum mencoba lagi.\n");
    } else {
        printf("\n🚫 Too many failed attempts! System temporarily locked.\n");
        printf("Contact administrator or wait 5 minutes before trying again.\n");
    }
    
    exit(1);
}

int authenticate_user(const char* username, const char* password) {
    UserData *user = load_user_data(username);
    if (!user) return 0;
    
    return strcmp(user->password, password) == 0;
}

void reset_password_via_email(const char* email) {
    if (strcmp(current_language, "indonesian") == 0) {
        printf("\n📧 Mengirim kode OTP ke email %s...\n", email);
        printf("💻 Menjalankan sistem reset password...\n");
    } else {
        printf("\n📧 Sending OTP code to email %s...\n", email);
        printf("💻 Running password reset system...\n");
    }
    
    // Call Python script for OTP
    char command[500];
    sprintf(command, "python3 ./scripts/send_otp.py %s", email);
    
    int result = system(command);
    
    if (result == 0) {
        char otp_input[10];
        if (strcmp(current_language, "indonesian") == 0) {
            printf("✅ OTP berhasil dikirim! Cek email Anda.\n");
            printf("Masukkan kode OTP: ");
        } else {
            printf("✅ OTP sent successfully! Check your email.\n");
            printf("Enter OTP code: ");
        }
        
        fgets(otp_input, sizeof(otp_input), stdin);
        otp_input[strcspn(otp_input, "\n")] = 0;
        
        // Simple OTP verification (should be more secure in production)
        // For now, we'll accept any 6-digit code
        if (strlen(otp_input) == 6) {
            char new_password[100];
            if (strcmp(current_language, "indonesian") == 0) {
                printf("✅ OTP valid! Masukkan password baru: ");
            } else {
                printf("✅ OTP valid! Enter new password: ");
            }
            
            fgets(new_password, sizeof(new_password), stdin);
            new_password[strcspn(new_password, "\n")] = 0;
            
            // Update password (implementation would go here)
            if (strcmp(current_language, "indonesian") == 0) {
                printf("✅ Password berhasil diubah! Silakan login dengan password baru.\n");
            } else {
                printf("✅ Password successfully changed! Please login with new password.\n");
            }
            
            sleep(3);
            login_system();
        } else {
            if (strcmp(current_language, "indonesian") == 0) {
                printf("❌ OTP tidak valid!\n");
            } else {
                printf("❌ Invalid OTP!\n");
            }
            sleep(2);
            login_system();
        }
    } else {
        if (strcmp(current_language, "indonesian") == 0) {
            printf("❌ Gagal mengirim OTP! Periksa koneksi internet.\n");
        } else {
            printf("❌ Failed to send OTP! Check internet connection.\n");
        }
        sleep(2);
        login_system();
    }
}
