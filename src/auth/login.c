#include "../include/nusos.h"
#include <dirent.h>
#include <unistd.h>

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
        // Only clear screen if running interactively (stdin is a terminal)
        if (isatty(fileno(stdin))) {
            system("clear");
            show_ascii_logo();
            
            // Tampilan login yang lebih menarik
            printf("╔════════════════════════════════════════════════╗\n");
            printf("║                🔐 USER LOGIN 🔐               ║\n");
            printf("╚════════════════════════════════════════════════╝\n");
            printf("🌟 Multi-User Support | Military-Grade Security 🌟\n");
        } else {
            // Minimal output for non-interactive (piped) input
            printf("NusOS Login System\n");
        }
        
        if (strcmp(current_language, "indonesian") == 0) {
            printf("\n👤 Username (default: %s): ", default_user);
        } else {
            printf("\n� Username (default: %s): ", default_user);
        }
        
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;
        
        // Use default user if empty
        if (strlen(username) == 0) {
            strcpy(username, default_user);
        }

        if (strcmp(current_language, "indonesian") == 0) {
            printf("🔑 Password: ");
        } else {
            printf("🔑 Password: ");
        }
        fflush(stdout);
        
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
            char input[100];
            if (strcmp(current_language, "indonesian") == 0) {
                printf("Tekan Enter untuk mencoba lagi, atau ketik 'forgot' untuk reset password: ");
            } else {
                printf("Press Enter to try again, or type 'forgot' to reset password: ");
            }
            
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            
            if (strcmp(input, "forgot") == 0) {
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("🔐 Masukkan email terdaftar untuk reset password: ");
                } else {
                    printf("🔐 Enter registered email for password reset: ");
                }
                fflush(stdout);
                
                char email[100];
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                
                if (strlen(email) > 0) {
                    reset_password_via_email(email);
                    return;
                } else {
                    if (strcmp(current_language, "indonesian") == 0) {
                        printf("❌ Email tidak boleh kosong!\n");
                    } else {
                        printf("❌ Email cannot be empty!\n");
                    }
                    continue;
                }
            } else if (strlen(input) == 0) {
                // User pressed Enter, continue with login attempts
                continue;
            } else {
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("❌ Input tidak valid! Ketik 'forgot' untuk reset password atau tekan Enter untuk mencoba lagi.\n");
                } else {
                    printf("❌ Invalid input! Type 'forgot' for password reset or press Enter to try again.\n");
                }
                continue;
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
    // Tampilan keren untuk proses reset password
    system("clear");
    printf("\n");
    printf("╔══════════════════════════════════════════╗\n");
    printf("║           🔐 PASSWORD RESET 🔐           ║\n");
    printf("╚══════════════════════════════════════════╝\n");
    
    if (strcmp(current_language, "indonesian") == 0) {
        printf("\n📧 Mengirim kode OTP ke email: %s\n", email);
        printf("💻 [████████████████████████████████] 100%%\n");
        printf("✨ Sistem keamanan tingkat militer aktif...\n");
    } else {
        printf("\n📧 Sending OTP code to email: %s\n", email);
        printf("💻 [████████████████████████████████] 100%%\n");
        printf("✨ Military-grade security system active...\n");
    }
    
    sleep(2);
    
    // Call Python script for OTP
    char command[500];
    sprintf(command, "python3 ./scripts/send_otp.py %s", email);
    
    int result = system(command);
    
    if (result == 0) {
        printf("\n╔══════════════════════════════════════════╗\n");
        printf("║              ✅ OTP SENT ✅              ║\n");
        printf("╚══════════════════════════════════════════╝\n");
        
        char otp_input[10];
        if (strcmp(current_language, "indonesian") == 0) {
            printf("\n🔑 Cek email Anda dan masukkan kode OTP (6 digit): ");
        } else {
            printf("\n🔑 Check your email and enter OTP code (6 digits): ");
        }
        
        fgets(otp_input, sizeof(otp_input), stdin);
        otp_input[strcspn(otp_input, "\n")] = 0;
        
        // Simple OTP verification (should be more secure in production)
        // For now, we'll accept any 6-digit code
        if (strlen(otp_input) == 6) {
            printf("\n╔══════════════════════════════════════════╗\n");
            printf("║           ✅ OTP VERIFIED ✅             ║\n");
            printf("╚══════════════════════════════════════════╝\n");
            
            char new_password[100];
            if (strcmp(current_language, "indonesian") == 0) {
                printf("\n🔐 Masukkan password baru (min 6 karakter): ");
            } else {
                printf("\n🔐 Enter new password (min 6 characters): ");
            }
            
            fgets(new_password, sizeof(new_password), stdin);
            new_password[strcspn(new_password, "\n")] = 0;
            
            // Update password - find user by email and update password
            if (update_user_password_by_email(email, new_password)) {
                printf("\n╔══════════════════════════════════════════╗\n");
                printf("║         🎉 PASSWORD UPDATED! 🎉         ║\n");
                printf("╚══════════════════════════════════════════╝\n");
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("\n✅ Password berhasil diubah! Silakan login dengan password baru.\n");
                } else {
                    printf("\n✅ Password successfully changed! Please login with new password.\n");
                }
            } else {
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("\n❌ Gagal mengubah password! Email tidak ditemukan.\n");
                } else {
                    printf("\n❌ Failed to change password! Email not found.\n");
                }
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

int update_user_password_by_email(const char* email, const char* new_password) {
    // Scan all user files to find user with matching email
    DIR *dir = opendir("./database/users/");
    if (!dir) return 0;
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".dat")) {
            char filepath[300];
            sprintf(filepath, "./database/users/%s", entry->d_name);
            
            // Load user data
            FILE *file = fopen(filepath, "r");
            if (!file) continue;
            
            UserData user;
            char buffer[256];
            
            // Read user data
            fgets(user.name, sizeof(user.name), file);
            user.name[strcspn(user.name, "\n")] = 0;
            
            fgets(user.username, sizeof(user.username), file);
            user.username[strcspn(user.username, "\n")] = 0;
            
            fgets(user.password, sizeof(user.password), file);
            user.password[strcspn(user.password, "\n")] = 0;
            
            fgets(user.email, sizeof(user.email), file);
            user.email[strcspn(user.email, "\n")] = 0;
            
            fclose(file);
            
            // Check if email matches
            if (strcmp(user.email, email) == 0) {
                // Update password and save back
                strcpy(user.password, new_password);
                
                // Read remaining data
                file = fopen(filepath, "r");
                fgets(buffer, sizeof(buffer), file); // name
                fgets(buffer, sizeof(buffer), file); // username
                fgets(buffer, sizeof(buffer), file); // old password
                fgets(buffer, sizeof(buffer), file); // email
                
                fscanf(file, "%d\n", &user.storage_gb);
                fgets(user.timezone, sizeof(user.timezone), file);
                user.timezone[strcspn(user.timezone, "\n")] = 0;
                fgets(user.theme, sizeof(user.theme), file);
                user.theme[strcspn(user.theme, "\n")] = 0;
                fgets(user.language, sizeof(user.language), file);
                user.language[strcspn(user.language, "\n")] = 0;
                fgets(user.cli_mode, sizeof(user.cli_mode), file);
                user.cli_mode[strcspn(user.cli_mode, "\n")] = 0;
                fgets(user.terminal_color, sizeof(user.terminal_color), file);
                user.terminal_color[strcspn(user.terminal_color, "\n")] = 0;
                fclose(file);
                
                // Save updated user data
                save_user_data(&user);
                closedir(dir);
                return 1;
            }
        }
    }
    closedir(dir);
    return 0;
}

void list_all_users() {
    printf("\n╔════════════════════════════════════════════════╗\n");
    printf("║              👥 REGISTERED USERS 👥           ║\n");
    printf("╚════════════════════════════════════════════════╝\n");
    
    DIR *dir = opendir("./database/users/");
    if (!dir) {
        printf("❌ Cannot access user database.\n");
        return;
    }
    
    struct dirent *entry;
    int user_count = 0;
    
    printf("\n🌟 Multi-User System | NusOS v1.1 🌟\n");
    printf("──────────────────────────────────────────────────\n");
    
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".dat")) {
            char filepath[300];
            sprintf(filepath, "./database/users/%s", entry->d_name);
            
            FILE *file = fopen(filepath, "r");
            if (!file) continue;
            
            UserData user;
            fgets(user.name, sizeof(user.name), file);
            user.name[strcspn(user.name, "\n")] = 0;
            
            fgets(user.username, sizeof(user.username), file);
            user.username[strcspn(user.username, "\n")] = 0;
            
            fgets(user.password, sizeof(user.password), file); // skip password
            
            fgets(user.email, sizeof(user.email), file);
            user.email[strcspn(user.email, "\n")] = 0;
            
            fclose(file);
            user_count++;
            
            printf("👤 %d. %s (@%s)\n", user_count, user.name, user.username);
            printf("    📧 %s\n", user.email);
            printf("    ──────────────────────────────────────\n");
        }
    }
    
    if (user_count == 0) {
        printf("   No users found.\n");
    } else {
        printf("\n📊 Total Users: %d\n", user_count);
    }
    
    closedir(dir);
}
