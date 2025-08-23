#include "../include/nusos.h"

void show_settings() {
    int choice;
    
    while (1) {
        system("clear");
        set_terminal_color();
        
        if (strcmp(current_language, "indonesian") == 0) {
            printf("⚙️  === PENGATURAN NUSOS === ⚙️\n");
            printf("═══════════════════════════════════\n");
            printf("👤 Profil Pengguna:\n");
            printf("   Nama: %s\n", current_user.name);
            printf("   Username: %s (permanen)\n", current_user.username);
            printf("   Email: %s\n", current_user.email);
            printf("   Storage: %d GB\n", current_user.storage_gb);
            printf("   Zona Waktu: %s\n", current_user.timezone);
            printf("   Bahasa: %s\n", current_user.language);
            printf("\n🎨 Tampilan:\n");
            printf("   Tema: %s\n", current_user.theme);
            printf("   Warna Terminal: %s\n", current_user.terminal_color);
            printf("   Mode CLI: %s\n", current_user.cli_mode);
            printf("\n═══════════════════════════════════\n");
            printf("1. 📝 Ganti Nama\n");
            printf("2. 📧 Ganti Email\n");
            printf("3. 🔧 Ganti Storage\n");
            printf("4. 🌍 Ganti Zona Waktu\n");
            printf("5. 🌐 Ganti Bahasa\n");
            printf("6. 🎨 Ganti Tema\n");
            printf("7. 🖥️  Ganti Warna Terminal\n");
            printf("8. ⌨️  Ganti Mode CLI\n");
            printf("9. 🔑 Ganti Password\n");
            printf("10. 🗑️ Hapus OS (BAHAYA!)\n");
            printf("0. ↩️  Kembali ke CLI\n");
            printf("═══════════════════════════════════\n");
            printf("Pilih opsi (0-10): ");
        } else {
            printf("⚙️  === NUSOS SETTINGS === ⚙️\n");
            printf("═══════════════════════════════════\n");
            printf("👤 User Profile:\n");
            printf("   Name: %s\n", current_user.name);
            printf("   Username: %s (permanent)\n", current_user.username);
            printf("   Email: %s\n", current_user.email);
            printf("   Storage: %d GB\n", current_user.storage_gb);
            printf("   Timezone: %s\n", current_user.timezone);
            printf("   Language: %s\n", current_user.language);
            printf("\n🎨 Appearance:\n");
            printf("   Theme: %s\n", current_user.theme);
            printf("   Terminal Color: %s\n", current_user.terminal_color);
            printf("   CLI Mode: %s\n", current_user.cli_mode);
            printf("\n═══════════════════════════════════\n");
            printf("1. 📝 Change Name\n");
            printf("2. 📧 Change Email\n");
            printf("3. 🔧 Change Storage\n");
            printf("4. 🌍 Change Timezone\n");
            printf("5. 🌐 Change Language\n");
            printf("6. 🎨 Change Theme\n");
            printf("7. 🖥️  Change Terminal Color\n");
            printf("8. ⌨️  Change CLI Mode\n");
            printf("9. 🔑 Change Password\n");
            printf("10. 🗑️ Delete OS (DANGER!)\n");
            printf("0. ↩️  Back to CLI\n");
            printf("═══════════════════════════════════\n");
            printf("Choose option (0-10): ");
        }
        
        reset_terminal_color();
        scanf("%d", &choice);
        getchar(); // Clear buffer
        
        switch (choice) {
            case 0:
                return;
                
            case 1: {
                char new_name[100];
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("Masukkan nama baru: ");
                } else {
                    printf("Enter new name: ");
                }
                fgets(new_name, sizeof(new_name), stdin);
                new_name[strcspn(new_name, "\n")] = 0;
                strcpy(current_user.name, new_name);
                save_user_data(&current_user);
                
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("✅ Nama berhasil diubah!\n");
                } else {
                    printf("✅ Name changed successfully!\n");
                }
                sleep(2);
                break;
            }
            
            case 2: {
                char new_email[100];
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("Masukkan email baru: ");
                } else {
                    printf("Enter new email: ");
                }
                fgets(new_email, sizeof(new_email), stdin);
                new_email[strcspn(new_email, "\n")] = 0;
                strcpy(current_user.email, new_email);
                save_user_data(&current_user);
                
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("✅ Email berhasil diubah!\n");
                } else {
                    printf("✅ Email changed successfully!\n");
                }
                sleep(2);
                break;
            }
            
            case 3: {
                int new_storage;
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("Masukkan ukuran storage baru (GB): ");
                } else {
                    printf("Enter new storage size (GB): ");
                }
                scanf("%d", &new_storage);
                current_user.storage_gb = new_storage;
                save_user_data(&current_user);
                
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("✅ Storage berhasil diubah!\n");
                } else {
                    printf("✅ Storage changed successfully!\n");
                }
                sleep(2);
                break;
            }
            
            case 4: {
                display_timezones();
                int tz_choice;
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("Pilih zona waktu baru (1-8): ");
                } else {
                    printf("Choose new timezone (1-8): ");
                }
                scanf("%d", &tz_choice);
                
                char timezones[][20] = {"WIB", "WITA", "WIT", "UTC+0", "UTC-5", "UTC+9", "UTC+8", "UTC+1"};
                if (tz_choice >= 1 && tz_choice <= 8) {
                    strcpy(current_user.timezone, timezones[tz_choice - 1]);
                    save_user_data(&current_user);
                    
                    if (strcmp(current_language, "indonesian") == 0) {
                        printf("✅ Zona waktu berhasil diubah!\n");
                    } else {
                        printf("✅ Timezone changed successfully!\n");
                    }
                }
                sleep(2);
                break;
            }
            
            case 5: {
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("1. English\n2. Bahasa Indonesia\nPilih bahasa (1-2): ");
                } else {
                    printf("1. English\n2. Bahasa Indonesia\nChoose language (1-2): ");
                }
                int lang_choice;
                scanf("%d", &lang_choice);
                
                if (lang_choice == 2) {
                    strcpy(current_user.language, "indonesian");
                    strcpy(current_language, "indonesian");
                } else {
                    strcpy(current_user.language, "english");
                    strcpy(current_language, "english");
                }
                save_user_data(&current_user);
                
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("✅ Bahasa berhasil diubah!\n");
                } else {
                    printf("✅ Language changed successfully!\n");
                }
                sleep(2);
                break;
            }
            
            case 6: {
                display_themes();
                int theme_choice;
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("Pilih tema baru (1-8): ");
                } else {
                    printf("Choose new theme (1-8): ");
                }
                scanf("%d", &theme_choice);
                
                char themes[][20] = {"dark_blue", "green_matrix", "purple_night", "orange_sunset", 
                                   "red_fire", "cyan_ocean", "white_clean", "gray_professional"};
                if (theme_choice >= 1 && theme_choice <= 8) {
                    strcpy(current_user.theme, themes[theme_choice - 1]);
                    save_user_data(&current_user);
                    
                    if (strcmp(current_language, "indonesian") == 0) {
                        printf("✅ Tema berhasil diubah!\n");
                    } else {
                        printf("✅ Theme changed successfully!\n");
                    }
                }
                sleep(2);
                break;
            }
            
            case 7: {
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("=== Pilihan Warna Terminal ===\n");
                    printf("1. Hijau\n2. Biru\n3. Merah\n4. Kuning\n5. Ungu\n6. Cyan\n7. Putih\n");
                    printf("Pilih warna (1-7): ");
                } else {
                    printf("=== Terminal Color Options ===\n");
                    printf("1. Green\n2. Blue\n3. Red\n4. Yellow\n5. Purple\n6. Cyan\n7. White\n");
                    printf("Choose color (1-7): ");
                }
                
                int color_choice;
                scanf("%d", &color_choice);
                
                char colors[][10] = {"green", "blue", "red", "yellow", "purple", "cyan", "white"};
                if (color_choice >= 1 && color_choice <= 7) {
                    strcpy(current_user.terminal_color, colors[color_choice - 1]);
                    save_user_data(&current_user);
                    
                    if (strcmp(current_language, "indonesian") == 0) {
                        printf("✅ Warna terminal berhasil diubah!\n");
                    } else {
                        printf("✅ Terminal color changed successfully!\n");
                    }
                }
                sleep(2);
                break;
            }
            
            case 8: {
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("=== Mode CLI ===\n");
                    printf("1. CMD saja\n2. Terminal saja\n3. CMD + Terminal\n");
                    printf("Pilih mode (1-3): ");
                } else {
                    printf("=== CLI Mode ===\n");
                    printf("1. CMD only\n2. Terminal only\n3. CMD + Terminal\n");
                    printf("Choose mode (1-3): ");
                }
                
                int cli_choice;
                scanf("%d", &cli_choice);
                
                switch(cli_choice) {
                    case 1: strcpy(current_user.cli_mode, "cmd"); break;
                    case 2: strcpy(current_user.cli_mode, "terminal"); break;
                    case 3: strcpy(current_user.cli_mode, "both"); break;
                    default: continue;
                }
                save_user_data(&current_user);
                
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("✅ Mode CLI berhasil diubah!\n");
                } else {
                    printf("✅ CLI mode changed successfully!\n");
                }
                sleep(2);
                break;
            }
            
            case 9: {
                char current_pass[100], new_pass[100];
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("Masukkan password saat ini: ");
                } else {
                    printf("Enter current password: ");
                }
                fgets(current_pass, sizeof(current_pass), stdin);
                current_pass[strcspn(current_pass, "\n")] = 0;
                
                if (strcmp(current_pass, current_user.password) == 0) {
                    if (strcmp(current_language, "indonesian") == 0) {
                        printf("Masukkan password baru: ");
                    } else {
                        printf("Enter new password: ");
                    }
                    fgets(new_pass, sizeof(new_pass), stdin);
                    new_pass[strcspn(new_pass, "\n")] = 0;
                    
                    strcpy(current_user.password, new_pass);
                    save_user_data(&current_user);
                    
                    if (strcmp(current_language, "indonesian") == 0) {
                        printf("✅ Password berhasil diubah!\n");
                    } else {
                        printf("✅ Password changed successfully!\n");
                    }
                } else {
                    if (strcmp(current_language, "indonesian") == 0) {
                        printf("❌ Password saat ini salah!\n");
                    } else {
                        printf("❌ Current password is incorrect!\n");
                    }
                }
                sleep(2);
                break;
            }
            
            case 10: {
                char confirmation[10];
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("⚠️  PERINGATAN: Ini akan menghapus SEMUA data NusOS!\n");
                    printf("Ketik 'HAPUS' untuk mengkonfirmasi: ");
                } else {
                    printf("⚠️  WARNING: This will delete ALL NusOS data!\n");
                    printf("Type 'DELETE' to confirm: ");
                }
                fgets(confirmation, sizeof(confirmation), stdin);
                confirmation[strcspn(confirmation, "\n")] = 0;
                
                if ((strcmp(current_language, "indonesian") == 0 && strcmp(confirmation, "HAPUS") == 0) ||
                    (strcmp(current_language, "english") == 0 && strcmp(confirmation, "DELETE") == 0)) {
                    
                    if (strcmp(current_language, "indonesian") == 0) {
                        printf("🗑️ Menghapus semua data NusOS...\n");
                        printf("👋 Terima kasih telah menggunakan NusOS!\n");
                    } else {
                        printf("🗑️ Deleting all NusOS data...\n");
                        printf("👋 Thank you for using NusOS!\n");
                    }
                    
                    // Delete all user data
                    system("rm -rf ./database");
                    exit(0);
                } else {
                    if (strcmp(current_language, "indonesian") == 0) {
                        printf("❌ Konfirmasi tidak valid. Operasi dibatalkan.\n");
                    } else {
                        printf("❌ Invalid confirmation. Operation cancelled.\n");
                    }
                    sleep(2);
                }
                break;
            }
            
            default:
                if (strcmp(current_language, "indonesian") == 0) {
                    printf("❌ Pilihan tidak valid!\n");
                } else {
                    printf("❌ Invalid option!\n");
                }
                sleep(1);
                break;
        }
    }
}
