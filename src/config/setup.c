#include "../include/nusos.h"

void set_terminal_color() {
    // Set terminal color based on user preference
    if (strcmp(current_user.terminal_color, "green") == 0) {
        printf("\033[32m");
    } else if (strcmp(current_user.terminal_color, "blue") == 0) {
        printf("\033[34m");
    } else if (strcmp(current_user.terminal_color, "red") == 0) {
        printf("\033[31m");
    } else if (strcmp(current_user.terminal_color, "yellow") == 0) {
        printf("\033[33m");
    } else if (strcmp(current_user.terminal_color, "purple") == 0) {
        printf("\033[35m");
    } else if (strcmp(current_user.terminal_color, "cyan") == 0) {
        printf("\033[36m");
    } else {
        printf("\033[37m"); // white
    }
}

void reset_terminal_color() {
    printf("\033[0m");
}

void setup_user_data() {
    UserData user;
    int theme_choice, timezone_choice;
    char themes[][20] = {"dark_blue", "green_matrix", "purple_night", "orange_sunset", 
                        "red_fire", "cyan_ocean", "white_clean", "gray_professional"};
    char timezones[][20] = {"WIB", "WITA", "WIT", "UTC+0", "UTC-5", "UTC+9", "UTC+8", "UTC+1"};
    
    if (strcmp(current_language, "indonesian") == 0) {
        printf("🚀 Mari siapkan NusOS untuk Anda! 🚀\n\n");
        
        printf("Masukkan nama lengkap: ");
        getchar(); // Clear buffer
        fgets(user.name, sizeof(user.name), stdin);
        user.name[strcspn(user.name, "\n")] = 0; // Remove newline
        
        printf("Masukkan username: ");
        fgets(user.username, sizeof(user.username), stdin);
        user.username[strcspn(user.username, "\n")] = 0;
        
        printf("Masukkan password: ");
        fgets(user.password, sizeof(user.password), stdin);
        user.password[strcspn(user.password, "\n")] = 0;
        
        printf("Masukkan email: ");
        fgets(user.email, sizeof(user.email), stdin);
        user.email[strcspn(user.email, "\n")] = 0;
        
        printf("Masukkan ukuran storage (GB): ");
        scanf("%d", &user.storage_gb);
        
        printf("\n");
        display_themes();
        printf("Pilih tema (1-8): ");
        scanf("%d", &theme_choice);
        strcpy(user.theme, themes[theme_choice - 1]);
        
        printf("\n");
        display_timezones();
        printf("Pilih zona waktu (1-8): ");
        scanf("%d", &timezone_choice);
        strcpy(user.timezone, timezones[timezone_choice - 1]);
        
        printf("\n=== Pilihan Mode CLI ===\n");
        printf("1. CMD saja\n");
        printf("2. Terminal saja\n");
        printf("3. CMD + Terminal (Gabungan)\n");
        printf("Pilih mode CLI (1-3): ");
        int cli_choice;
        scanf("%d", &cli_choice);
        
        switch(cli_choice) {
            case 1: strcpy(user.cli_mode, "cmd"); break;
            case 2: strcpy(user.cli_mode, "terminal"); break;
            case 3: strcpy(user.cli_mode, "both"); break;
            default: strcpy(user.cli_mode, "both"); break;
        }
        
        printf("\n=== Pilihan Warna Terminal ===\n");
        printf("1. Hijau\n");
        printf("2. Biru\n");
        printf("3. Merah\n");
        printf("4. Kuning\n");
        printf("5. Ungu\n");
        printf("6. Cyan\n");
        printf("7. Putih\n");
        printf("Pilih warna terminal (1-7): ");
        int color_choice;
        scanf("%d", &color_choice);
        
        char colors[][10] = {"green", "blue", "red", "yellow", "purple", "cyan", "white"};
        strcpy(user.terminal_color, colors[color_choice - 1]);
        
    } else {
        printf("🚀 Let's set up NusOS for you! 🚀\n\n");
        
        printf("Enter full name: ");
        getchar(); // Clear buffer
        fgets(user.name, sizeof(user.name), stdin);
        user.name[strcspn(user.name, "\n")] = 0;
        
        printf("Enter username: ");
        fgets(user.username, sizeof(user.username), stdin);
        user.username[strcspn(user.username, "\n")] = 0;
        
        printf("Enter password: ");
        fgets(user.password, sizeof(user.password), stdin);
        user.password[strcspn(user.password, "\n")] = 0;
        
        printf("Enter email: ");
        fgets(user.email, sizeof(user.email), stdin);
        user.email[strcspn(user.email, "\n")] = 0;
        
        printf("Enter storage size (GB): ");
        scanf("%d", &user.storage_gb);
        
        printf("\n");
        display_themes();
        printf("Choose theme (1-8): ");
        scanf("%d", &theme_choice);
        strcpy(user.theme, themes[theme_choice - 1]);
        
        printf("\n");
        display_timezones();
        printf("Choose timezone (1-8): ");
        scanf("%d", &timezone_choice);
        strcpy(user.timezone, timezones[timezone_choice - 1]);
        
        printf("\n=== CLI Mode Options ===\n");
        printf("1. CMD only\n");
        printf("2. Terminal only\n");
        printf("3. CMD + Terminal (Combined)\n");
        printf("Choose CLI mode (1-3): ");
        int cli_choice;
        scanf("%d", &cli_choice);
        
        switch(cli_choice) {
            case 1: strcpy(user.cli_mode, "cmd"); break;
            case 2: strcpy(user.cli_mode, "terminal"); break;
            case 3: strcpy(user.cli_mode, "both"); break;
            default: strcpy(user.cli_mode, "both"); break;
        }
        
        printf("\n=== Terminal Color Options ===\n");
        printf("1. Green\n");
        printf("2. Blue\n");
        printf("3. Red\n");
        printf("4. Yellow\n");
        printf("5. Purple\n");
        printf("6. Cyan\n");
        printf("7. White\n");
        printf("Choose terminal color (1-7): ");
        int color_choice;
        scanf("%d", &color_choice);
        
        char colors[][10] = {"green", "blue", "red", "yellow", "purple", "cyan", "white"};
        strcpy(user.terminal_color, colors[color_choice - 1]);
    }
    
    strcpy(user.language, current_language);
    
    // Save user data
    save_user_data(&user);
    
    if (strcmp(current_language, "indonesian") == 0) {
        printf("\n✅ Setup berhasil! Selamat datang di NusOS, %s!\n", user.name);
        printf("🎉 Sistem akan restart untuk menerapkan konfigurasi...\n");
    } else {
        printf("\n✅ Setup successful! Welcome to NusOS, %s!\n", user.name);
        printf("🎉 System will restart to apply configuration...\n");
    }
    
    sleep(3);
    system("clear");
}

void save_user_data(UserData *user) {
    char filepath[300];
    sprintf(filepath, "./database/users/%s.dat", user->username);
    
    FILE *file = fopen(filepath, "w");
    if (file) {
        fprintf(file, "%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n",
                user->name, user->username, user->password, user->email,
                user->storage_gb, user->timezone, user->theme, user->language,
                user->cli_mode, user->terminal_color);
        fclose(file);
    }
    
    // Save current user as default
    FILE *default_file = fopen("./database/config/default_user", "w");
    if (default_file) {
        fprintf(default_file, "%s", user->username);
        fclose(default_file);
    }
}

UserData* load_user_data(const char* username) {
    static UserData user;
    char filepath[300];
    sprintf(filepath, "./database/users/%s.dat", username);
    
    FILE *file = fopen(filepath, "r");
    if (!file) return NULL;
    
    char buffer[300];
    
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(user.name, buffer);
    
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(user.username, buffer);
    
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(user.password, buffer);
    
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(user.email, buffer);
    
    fscanf(file, "%d\n", &user.storage_gb);
    
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(user.timezone, buffer);
    
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(user.theme, buffer);
    
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(user.language, buffer);
    
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(user.cli_mode, buffer);
    
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = 0;
    strcpy(user.terminal_color, buffer);
    
    fclose(file);
    return &user;
}
