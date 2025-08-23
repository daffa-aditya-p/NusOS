#include "../include/nusos.h"

// Global variables
SystemConfig sys_config = {
    .os_name = "NusOS",
    .version = "1.0.0",
    .database_path = "./database/",
    .config_path = "./database/config/"
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
    printf("=== Language Selection / Pilihan Bahasa ===\n");
    printf("1. English\n");
    printf("2. Bahasa Indonesia\n");
    printf("Select/Pilih (1-2): ");
    scanf("%d", &choice);
    
    if (choice == 2) {
        strcpy(current_language, "indonesian");
    } else {
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
    
    // Check if first time setup
    FILE *setup_check = fopen("./database/config/setup_complete", "r");
    if (setup_check == NULL) {
        // First time setup
        setup_user_data();
        
        // Create setup complete flag
        FILE *flag = fopen("./database/config/setup_complete", "w");
        if (flag) {
            fprintf(flag, "1");
            fclose(flag);
        }
    } else {
        fclose(setup_check);
    }
    
    // Start login system
    login_system();
    
    return 0;
}
