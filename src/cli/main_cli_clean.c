#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct UserData {
    char name[100];
    char username[50];
    char password[50];
    char email[100];
    int storage_gb;
    char theme[50];
    char timezone[50];
    char cli_mode[50];
    char language[20];
} current_user;

extern char current_language[20];

void main_cli() {
    char command[256];
    
    printf("Welcome to NusOS CLI!\n");
    printf("Current user: %s\n", current_user.username);
    printf("Type 'help' for commands, 'exit' to quit.\n\n");
    
    while (1) {
        printf("%s@NusOS$ ", current_user.username);
        
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }
        
        // Remove newline
        command[strcspn(command, "\n")] = 0;
        
        if (strlen(command) == 0) {
            continue;
        }
        
        if (strcmp(command, "help") == 0) {
            printf("\nAvailable commands:\n");
            printf("  help     - Show this help\n");
            printf("  exit     - Exit CLI\n");
            printf("  logout   - Logout from system\n");
            printf("\n");
        }
        else if (strcmp(command, "exit") == 0 || strcmp(command, "logout") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Unknown command: %s\n", command);
            printf("Type 'help' for available commands.\n");
        }
    }
}
