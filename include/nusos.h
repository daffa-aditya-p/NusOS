#ifndef NUSOS_H
#define NUSOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

// Struktur untuk menyimpan data user
typedef struct {
    char name[100];
    char username[50];
    char password[100];
    char email[100];
    int storage_gb;
    char timezone[50];
    char theme[50];
    char language[20];
    char cli_mode[20]; // "cmd", "terminal", "both"
    char terminal_color[20];
} UserData;

// Struktur untuk konfigurasi sistem
typedef struct {
    char os_name[50];
    char version[20];
    char database_path[200];
    char config_path[200];
} SystemConfig;

// Function declarations
void show_ascii_logo();
void setup_initial_language();
void setup_user_data();
void save_user_data(UserData *user);
UserData* load_user_data(const char* username);
void boot_sequence();
void login_system();
void main_cli();
void show_settings();
void reset_password_via_email(const char* email);
int authenticate_user(const char* username, const char* password);
void create_directories();
void show_welcome_message();
void display_themes();
void display_timezones();
void set_terminal_color();
void reset_terminal_color();

// Global variables
extern SystemConfig sys_config;
extern UserData current_user;
extern char current_language[20];

#endif // NUSOS_H
