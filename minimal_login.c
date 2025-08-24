#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Include authentication function
typedef struct {
    char name[100];
    char username[50];
    char password[100];
    char email[100];
    int storage_gb;
    char timezone[20];
    char theme[20];
    char language[20];
    char cli_mode[20];
    char terminal_color[20];
} User;

int authenticate_user(const char* username, const char* password) {
    char filepath[200];
    snprintf(filepath, sizeof(filepath), "./database/users/%s.dat", username);
    
    FILE *file = fopen(filepath, "r");
    if (!file) {
        return 0;
    }
    
    User user;
    fgets(user.name, sizeof(user.name), file);
    fgets(user.username, sizeof(user.username), file);
    fgets(user.password, sizeof(user.password), file);
    
    // Remove newlines
    user.name[strcspn(user.name, "\n")] = 0;
    user.username[strcspn(user.username, "\n")] = 0;
    user.password[strcspn(user.password, "\n")] = 0;
    
    fclose(file);
    
    return (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0);
}

int main() {
    char username[50], password[50];
    
    // Minimal UI
    printf("NusOS Login\n");
    printf("Username: ");
    fflush(stdout);
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("Password: ");
    fflush(stdout);
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;
    
    printf("\nTesting authentication...\n");
    if (authenticate_user(username, password)) {
        printf("SUCCESS: Login successful for user '%s'!\n", username);
        printf("Welcome to NusOS!\n");
        return 0;
    } else {
        printf("FAILED: Invalid username or password.\n");
        return 1;
    }
}
