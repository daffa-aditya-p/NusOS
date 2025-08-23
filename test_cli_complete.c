#include <stdio.h>
#include <string.h>

extern char current_language[20];

typedef struct {
    char username[50];
    char theme[50];
    char timezone[50];
    char cli_mode[20];
    char terminal_color[20];
} UserData;

extern UserData current_user;

void set_terminal_color() {
    printf("\033[32m");
}

void reset_terminal_color() {
    printf("\033[0m");
}

void show_settings() {
    printf("Settings placeholder\n");
}

void main_cli() {
    printf("🎉 Welcome to NusOS CLI! 🎉\n");
    printf("Type 'exit' to quit.\n\n");
    
    char command[256];
    while (1) {
        set_terminal_color();
        printf("%s@NusOS$ ", current_user.username);
        reset_terminal_color();
        
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }
        
        command[strcspn(command, "\n")] = 0;
        
        if (strlen(command) == 0) {
            continue;
        }
        
        if (strcmp(command, "exit") == 0 || strcmp(command, "logout") == 0) {
            printf("👋 Goodbye!\n");
            break;
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands: exit, help, settings\n");
        } else if (strcmp(command, "settings") == 0) {
            show_settings();
        } else {
            printf("Unknown command: %s\n", command);
            printf("Type 'help' for available commands.\n");
        }
    }
}
