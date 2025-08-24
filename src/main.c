#include "../include/nusos.h"
#include <stdlib.h>
#include <stdio.h>

// Global variables
SystemConfig sys_config = {
    .os_name = "NusOS",
    .version = "1.0.1",
    .kernel_version = "5.15.0-nusos-1.0.1",
    .build_date = __DATE__ " " __TIME__,
    .database_path = "./database/",
    .config_path = "./database/config/",
    .security_level = 3,
    .encryption_enabled = 1,
    .plugin_support = 1
};

UserData current_user = {
    .username = "user",
    .theme = "dark_blue",
    .timezone = "UTC",
    .cli_mode = "both",
    .terminal_color = "green"
};
char current_language[20] = "english";

void show_ascii_logo() {
    printf("\n");
    printf("███╗   ██╗██╗   ██╗███████╗ ██████╗ ███████╗\n");
    printf("████╗  ██║██║   ██║██╔════╝██╔═══██╗██╔════╝\n");
    printf("██╔██╗ ██║██║   ██║███████╗██║   ██║███████╗\n");
    printf("██║╚██╗██║██║   ██║╚════██║██║   ██║╚════██║\n");
    printf("██║ ╚████║╚██████╔╝███████║╚██████╔╝███████║\n");
    printf("╚═╝  ╚═══╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚══════╝\n");
    printf("\n");
    if (strcmp(current_language, "indonesian") == 0) {
        printf("🌟 Selamat datang di NusOS - Sistem Operasi Terbaik di Dunia! 🌟\n");
        printf("💫 OS Tercepat, Teringan, dan Teraman tahun 2025! 💫\n");
    } else {
        printf("🌟 Welcome to NusOS - The World's Best Operating System! 🌟\n");
        printf("💫 Fastest, Lightest, and Most Secure OS of 2025! 💫\n");
    }
    printf("\n");
}

void setup_initial_language() {
    int choice;
    char buffer[100];
    
    printf("=== Language Selection / Pilihan Bahasa ===\n");
    printf("1. English\n");
    printf("2. Bahasa Indonesia\n");
    printf("Select/Pilih (1-2): ");
    fflush(stdout);
    
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        choice = atoi(buffer);
        if (choice == 2) {
            strcpy(current_language, "indonesian");
        } else {
            strcpy(current_language, "english");
        }
    } else {
        // Default to English if input fails
        strcpy(current_language, "english");
    }
    
    system("clear");
}

void display_themes() {
    if (strcmp(current_language, "indonesian") == 0) {
        printf("=== Pilihan Tema ===\n");
        printf("1. Dark Blue (Biru Gelap)\n");
        printf("2. Green Matrix (Hijau Matrix)\n");
        printf("3. Purple Night (Ungu Malam)\n");
        printf("4. Orange Sunset (Jingga Senja)\n");
        printf("5. Red Fire (Merah Api)\n");
        printf("6. Cyan Ocean (Cyan Lautan)\n");
        printf("7. White Clean (Putih Bersih)\n");
        printf("8. Gray Professional (Abu-abu Profesional)\n");
    } else {
        printf("=== Theme Selection ===\n");
        printf("1. Dark Blue\n");
        printf("2. Green Matrix\n");
        printf("3. Purple Night\n");
        printf("4. Orange Sunset\n");
        printf("5. Red Fire\n");
        printf("6. Cyan Ocean\n");
        printf("7. White Clean\n");
        printf("8. Gray Professional\n");
    }
}

void display_timezones() {
    if (strcmp(current_language, "indonesian") == 0) {
        printf("=== Pilihan Zona Waktu ===\n");
        printf("1. WIB (Jakarta, Indonesia)\n");
        printf("2. WITA (Makassar, Indonesia)\n");
        printf("3. WIT (Jayapura, Indonesia)\n");
        printf("4. UTC+0 (London)\n");
        printf("5. UTC-5 (New York)\n");
        printf("6. UTC+9 (Tokyo)\n");
        printf("7. UTC+8 (Singapore)\n");
        printf("8. UTC+1 (Berlin)\n");
    } else {
        printf("=== Timezone Selection ===\n");
        printf("1. WIB (Jakarta, Indonesia)\n");
        printf("2. WITA (Makassar, Indonesia)\n");
        printf("3. WIT (Jayapura, Indonesia)\n");
        printf("4. UTC+0 (London)\n");
        printf("5. UTC-5 (New York)\n");
        printf("6. UTC+9 (Tokyo)\n");
        printf("7. UTC+8 (Singapore)\n");
        printf("8. UTC+1 (Berlin)\n");
    }
}

void create_directories() {
    struct stat st = {0};
    
    // Create database directory
    if (stat("./database", &st) == -1) {
        mkdir("./database", 0700);
    }
    
    // Create config directory
    if (stat("./database/config", &st) == -1) {
        mkdir("./database/config", 0700);
    }
    
    // Create users directory
    if (stat("./database/users", &st) == -1) {
        mkdir("./database/users", 0700);
    }
}

int main() {
    create_directories();
    setup_initial_language();
    show_ascii_logo();
    
    // Initialize kernel silently
    init_nusos_kernel();
    
    // Check if first time setup
    FILE *setup_check = fopen("./database/config/setup_complete", "r");
    if (setup_check == NULL) {
        // For debugging - create a default user instead of interactive setup
        printf("Creating default user for testing...\n");
        
        // Create default user data
        UserData default_user = {
            .name = "Test User",
            .username = "testuser",
            .password = "password123",
            .email = "test@example.com",
            .storage_gb = 50,
            .theme = "dark_blue",
            .timezone = "UTC+0",
            .cli_mode = "both",
            .terminal_color = "green"
        };
        
        // Save user data
        char user_file[256];
        snprintf(user_file, sizeof(user_file), "./database/users/%s.dat", default_user.username);
        FILE *file = fopen(user_file, "w");
        if (file) {
            fprintf(file, "%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n",
                    default_user.name, default_user.username, default_user.password,
                    default_user.email, default_user.storage_gb, default_user.theme,
                    default_user.timezone, default_user.cli_mode, default_user.terminal_color);
            fclose(file);
        }
        
        // Create default user flag
        FILE *default_flag = fopen("./database/config/default_user", "w");
        if (default_flag) {
            fprintf(default_flag, "%s", default_user.username);
            fclose(default_flag);
        }
        
        // Create setup complete flag
        FILE *flag = fopen("./database/config/setup_complete", "w");
        if (flag) {
            fprintf(flag, "1");
            fclose(flag);
        }
        
        printf("Default user created successfully!\n");
    } else {
        fclose(setup_check);
    }
    
    // Start login system
    login_system();
    
    return 0;
}
