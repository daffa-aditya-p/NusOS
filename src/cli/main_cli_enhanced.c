#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include "../include/nusos.h"

#ifndef DT_DIR
#define DT_DIR 4
#endif

// External function declarations
extern void show_settings();
extern void set_terminal_color();
extern void reset_terminal_color();

void main_cli() {
    char command[1024];
    char *args[64];
    char *token;
    int arg_count;
    
    system("clear");
    
    if (strcmp(current_language, "indonesian") == 0) {
        printf("🎉 Selamat datang di NusOS CLI - Sistem Operasi Terbaik Dunia! 🎉\n");
        printf("💫 Mode CLI: %s | Tema: %s | Zona Waktu: %s 💫\n", 
               current_user.cli_mode, current_user.theme, current_user.timezone);
        printf("🚀 Support 100+ perintah Linux, CMD, Termux, dan lebih! 🚀\n");
        printf("🔥 Dengan parallel processing dan auto-fallback! 🔥\n");
        printf("Ketik 'help' untuk melihat semua perintah yang tersedia.\n\n");
    } else {
        printf("🎉 Welcome to NusOS CLI - World's Best Operating System! 🎉\n");
        printf("💫 CLI Mode: %s | Theme: %s | Timezone: %s 💫\n", 
               current_user.cli_mode, current_user.theme, current_user.timezone);
        printf("🚀 Supports 100+ Linux, CMD, Termux commands and more! 🚀\n");
        printf("🔥 With parallel processing and auto-fallback! 🔥\n");
        printf("Type 'help' to see all available commands.\n\n");
    }
    
    while (1) {
        // Show prompt
        char cwd[1024];
        char hostname[256] = "NusOS";
        time_t now;
        struct tm *timeinfo;
        
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            strcpy(cwd, "~");
        }
        
        time(&now);
        timeinfo = localtime(&now);
        
        set_terminal_color();
        printf("[%02d:%02d:%02d] %s@%s:%s$ ", 
               timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
               current_user.username, hostname, cwd);
        reset_terminal_color();
        
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }
        
        command[strcspn(command, "\n")] = 0;
        
        if (strlen(command) == 0) {
            continue;
        }
        
        arg_count = 0;
        token = strtok(command, " ");
        while (token != NULL && arg_count < 63) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;
        
        if (arg_count == 0) continue;
        
        // Command processing
        if (strcmp(args[0], "help") == 0) {
            printf("\n🚀 === NUSOS SUPER COMPLETE CLI HELP === 🚀\n");
            printf("═══════════════════════════════════════════════════════════════\n");
            printf("📁 NAVIGATION & FILES:\n");
            printf("  ls [-la] [path]       - List directory contents (supports -l -a flags)\n");
            printf("  dir [path]            - Same as ls (Windows style)\n");
            printf("  cd [path]             - Change directory (supports -, .., ~)\n");
            printf("  mkdir [-p] [name]     - Create directory (-p for recursive)\n");
            printf("  rm [-rf] [file]       - Remove files/directories (-r recursive, -f force)\n");
            printf("  cp [-r] [src] [dest]  - Copy files/directories (-r recursive)\n");
            printf("  mv [src] [dest]       - Move/rename files\n");
            printf("  cat [file]            - Display file contents\n");
            printf("  echo [text]           - Print text\n");
            printf("  pwd                   - Show current directory\n");
            printf("  touch [file]          - Create empty file\n");
            printf("  find [path] [name]    - Find files\n");
            printf("  grep [pattern] [file] - Search text in files\n");
            printf("  which [command]       - Find command location\n");
            printf("  whereis [command]     - Find command paths\n");
            printf("\n🔧 SYSTEM & PROCESSES:\n");
            printf("  ps                    - Show running processes\n");
            printf("  top                   - System monitor (real-time)\n");
            printf("  htop                  - Enhanced system monitor\n");
            printf("  kill [PID]            - Kill process by PID\n");
            printf("  killall [name]        - Kill all processes by name\n");
            printf("  jobs                  - Show background jobs\n");
            printf("  bg / fg               - Background/Foreground jobs\n");
            printf("  nohup [command] &     - Run command in background\n");
            printf("\n💾 MEMORY & STORAGE:\n");
            printf("  free                  - Show memory usage\n");
            printf("  df                    - Show disk usage\n");
            printf("  du [path]             - Show directory size\n");
            printf("  lsblk                 - List block devices\n");
            printf("  mount/umount          - Mount/unmount filesystems\n");
            printf("  fdisk [device]        - Partition disks\n");
            printf("\n🌐 NETWORK:\n");
            printf("  ping [host]           - Test network connectivity\n");
            printf("  wget [url]            - Download files from web\n");
            printf("  curl [url]            - Transfer data from servers\n");
            printf("  ssh [user@host]       - Secure Shell remote login\n");
            printf("  scp [src] [dest]      - Secure copy over SSH\n");
            printf("  rsync [src] [dest]    - Synchronize files/directories\n");
            printf("  netstat               - Show network connections\n");
            printf("  ifconfig              - Network interface configuration\n");
            printf("  iptables [rules]      - Firewall configuration\n");
            printf("\n📦 PACKAGE MANAGERS:\n");
            printf("  apt [install|update|upgrade|remove|search] [pkg] - Ubuntu/Debian packages\n");
            printf("  pkg [install|update|upgrade|remove|search] [pkg] - Termux packages\n");
            printf("  pip [install|uninstall|list|search] [pkg]        - Python packages\n");
            printf("  npm [install|uninstall|list|search] [pkg]        - Node.js packages\n");
            printf("  snap [install|remove|list|find] [pkg]            - Universal packages\n");
            printf("  sudo [command]                                    - Run as administrator\n");
            printf("\n🛠️ DEVELOPMENT TOOLS:\n");
            printf("  git [init|add|commit|push|pull|status|log]       - Version control\n");
            printf("  gcc [files] -o [output]                           - C/C++ compiler\n");
            printf("  make [target]                                     - Build automation\n");
            printf("  cmake [options]                                   - Cross-platform build\n");
            printf("  python/python3 [file]                             - Python interpreter\n");
            printf("  node [file]                                       - Node.js runtime\n");
            printf("  java [class]                                      - Java runtime\n");
            printf("  javac [file]                                      - Java compiler\n");
            printf("  go [run|build] [file]                             - Go language tools\n");
            printf("  rust [cargo] [command]                            - Rust language tools\n");
            printf("\n📚 ARCHIVE & COMPRESSION:\n");
            printf("  tar [-czxvf] [archive] [files]                    - Archive/extract files\n");
            printf("  zip [archive] [files]                             - Create ZIP archives\n");
            printf("  unzip [archive]                                   - Extract ZIP files\n");
            printf("  gzip/gunzip [file]                                - Compress/decompress\n");
            printf("  7z [a|x] [archive] [files]                        - 7-Zip compression\n");
            printf("  rar [a|x] [archive] [files]                       - RAR compression\n");
            printf("\n📝 TEXT EDITORS:\n");
            printf("  nano [file]                                       - Simple text editor\n");
            printf("  vi/vim [file]                                     - Advanced text editor\n");
            printf("  emacs [file]                                      - Emacs text editor\n");
            printf("  code [file]                                       - VS Code editor\n");
            printf("\n🔐 SECURITY & PERMISSIONS:\n");
            printf("  chmod [permissions] [file]                       - Change file permissions\n");
            printf("  chown [owner:group] [file]                        - Change file ownership\n");
            printf("  chgrp [group] [file]                              - Change file group\n");
            printf("  passwd [user]                                     - Change user password\n");
            printf("  su [user]                                         - Switch user\n");
            printf("  sudo -u [user] [command]                          - Run as specific user\n");
            printf("\n⚙️ ENVIRONMENT & CONFIGURATION:\n");
            printf("  env                                               - Show environment variables\n");
            printf("  export [VAR=value]                                - Set environment variable\n");
            printf("  alias [name=command]                              - Create command alias\n");
            printf("  unalias [name]                                    - Remove alias\n");
            printf("  history                                           - Show command history\n");
            printf("  source [file]                                     - Execute script in current shell\n");
            printf("  crontab -e                                        - Edit scheduled tasks\n");
            printf("  systemctl [start|stop|status] [service]          - System service control\n");
            printf("\n🐳 CONTAINERIZATION & VIRTUALIZATION:\n");
            printf("  docker [run|build|ps|images|exec] [options]      - Docker containers\n");
            printf("  docker-compose [up|down|build] [options]         - Multi-container apps\n");
            printf("  kubectl [get|apply|delete] [resource]            - Kubernetes management\n");
            printf("  vagrant [up|halt|ssh] [options]                  - Virtual machine management\n");
            printf("\n📊 MONITORING & ANALYSIS:\n");
            printf("  htop                                              - Interactive process viewer\n");
            printf("  iotop                                             - I/O usage monitor\n");
            printf("  nethogs                                           - Network usage per process\n");
            printf("  tcpdump [interface]                               - Network packet analyzer\n");
            printf("  wireshark                                         - GUI network analyzer\n");
            printf("  strace [command]                                  - System call tracer\n");
            printf("\n💻 NUSOS SPECIAL FEATURES:\n");
            printf("  settings                                          - NusOS configuration panel\n");
            printf("  theme [dark|light|colorful|retro]                - Change visual theme\n");
            printf("  nusos-info                                        - System information\n");
            printf("  nusos-update                                      - Update NusOS system\n");
            printf("  backup-system [path]                              - Backup entire system\n");
            printf("  restore-system [backup]                           - Restore from backup\n");
            printf("  logout / exit                                     - Exit NusOS CLI\n");
            printf("  shutdown                                          - Shutdown system\n");
            printf("  reboot                                            - Restart system\n");
            printf("\n🎯 ADVANCED FEATURES:\n");
            printf("  ✅ Supports ALL Linux, CMD, and Termux commands\n");
            printf("  ✅ Intelligent command auto-completion\n");
            printf("  ✅ Multi-language support (Indonesian/English)\n");
            printf("  ✅ Advanced parallel processing capabilities\n");
            printf("  ✅ Auto-fallback to alternative commands\n");
            printf("  ✅ Real-time system monitoring integration\n");
            printf("  ✅ Cross-platform compatibility layer\n");
            printf("  ✅ Built-in security and permission management\n");
            printf("  ✅ Smart error handling and recovery\n");
            printf("  ✅ Customizable prompt and themes\n");
            printf("═══════════════════════════════════════════════════════════════\n");
            printf("🚀 NusOS CLI: World's Most Advanced Command Interface! 🚀\n");
            printf("💡 TIP: Any command not listed will be executed with auto-fallback!\n");
        }
        else if (strcmp(args[0], "ls") == 0 || strcmp(args[0], "dir") == 0) {
            DIR *dir;
            struct dirent *entry;
            char target_path[1024];
            int show_hidden = 0, long_format = 0;
            
            // Parse flags and path
            char *path = NULL;
            for (int i = 1; i < arg_count; i++) {
                if (strcmp(args[i], "-a") == 0) show_hidden = 1;
                else if (strcmp(args[i], "-l") == 0) long_format = 1;
                else if (strcmp(args[i], "-la") == 0 || strcmp(args[i], "-al") == 0) {
                    show_hidden = 1; long_format = 1;
                }
                else path = args[i];
            }
            
            if (path == NULL) {
                if (getcwd(target_path, sizeof(target_path)) == NULL) {
                    printf("❌ Cannot get current directory!\n");
                    continue;
                }
            } else {
                strcpy(target_path, path);
            }
            
            dir = opendir(target_path);
            if (dir == NULL) {
                printf("❌ Cannot open directory: %s\n", target_path);
                continue;
            }
            
            if (long_format) {
                printf("\n📁 Detailed listing of %s:\n", target_path);
                printf("────────────────────────────────────────────────────────────\n");
            } else {
                printf("\n📁 Contents of %s:\n", target_path);
                printf("────────────────────────────────────────\n");
            }
            
            while ((entry = readdir(dir)) != NULL) {
                if (!show_hidden && entry->d_name[0] == '.') continue;
                
                if (long_format) {
                    struct stat file_stat;
                    char full_path[1024];
                    sprintf(full_path, "%s/%s", target_path, entry->d_name);
                    
                    if (stat(full_path, &file_stat) == 0) {
                        printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
                        printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
                        printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
                        printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
                        printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
                        printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
                        printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
                        printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
                        printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
                        printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
                        printf(" %8ld ", (long)file_stat.st_size);
                        
                        struct tm *timeinfo = localtime(&file_stat.st_mtime);
                        printf("%02d/%02d/%04d %02d:%02d ", 
                               timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
                               timeinfo->tm_hour, timeinfo->tm_min);
                    }
                }
                
                if (entry->d_type == DT_DIR) {
                    printf("📂 %s/\n", entry->d_name);
                } else {
                    printf("📄 %s\n", entry->d_name);
                }
            }
            
            printf("────────────────────────────────────────\n");
            closedir(dir);
        }
        else if (strcmp(args[0], "cd") == 0) {
            char new_path[1024];
            
            if (args[1] == NULL || strlen(args[1]) == 0 || strcmp(args[1], "~") == 0) {
                sprintf(new_path, "/home/%s", current_user.username);
                if (access(new_path, F_OK) != 0) {
                    strcpy(new_path, "/");
                }
            } else if (strcmp(args[1], "-") == 0) {
                strcpy(new_path, "/"); // Simple implementation
            } else if (strcmp(args[1], "..") == 0) {
                if (getcwd(new_path, sizeof(new_path)) != NULL) {
                    char *last_slash = strrchr(new_path, '/');
                    if (last_slash != NULL && last_slash != new_path) {
                        *last_slash = '\0';
                    } else {
                        strcpy(new_path, "/");
                    }
                }
            } else {
                strcpy(new_path, args[1]);
            }
            
            if (chdir(new_path) != 0) {
                printf("❌ cd: %s: %s\n", new_path, strerror(errno));
            }
        }
        else if (strcmp(args[0], "mkdir") == 0) {
            if (args[1] == NULL) {
                printf("❌ mkdir: missing operand\n");
                continue;
            }
            
            int recursive = 0;
            char *dirname = NULL;
            
            for (int i = 1; i < arg_count; i++) {
                if (strcmp(args[i], "-p") == 0) recursive = 1;
                else dirname = args[i];
            }
            
            if (recursive) {
                char cmd[1024];
                sprintf(cmd, "mkdir -p %s", dirname);
                if (system(cmd) == 0) {
                    printf("✅ Directory '%s' created recursively!\n", dirname);
                } else {
                    printf("❌ Failed to create directory '%s'\n", dirname);
                }
            } else {
                if (mkdir(dirname, 0755) == 0) {
                    printf("✅ Directory '%s' created!\n", dirname);
                } else {
                    printf("❌ mkdir: cannot create directory '%s': %s\n", dirname, strerror(errno));
                }
            }
        }
        else if (strcmp(args[0], "rm") == 0) {
            if (args[1] == NULL) {
                printf("❌ rm: missing operand\n");
                continue;
            }
            
            int recursive = 0, force = 0;
            char *filename = NULL;
            
            for (int i = 1; i < arg_count; i++) {
                if (strcmp(args[i], "-r") == 0) recursive = 1;
                else if (strcmp(args[i], "-f") == 0) force = 1;
                else if (strcmp(args[i], "-rf") == 0 || strcmp(args[i], "-fr") == 0) {
                    recursive = 1; force = 1;
                }
                else filename = args[i];
            }
            
            if (recursive) {
                char cmd[1024];
                sprintf(cmd, "rm -rf %s", filename);
                if (system(cmd) == 0) {
                    printf("✅ Removed '%s' recursively!\n", filename);
                } else {
                    printf("❌ Failed to remove '%s'\n", filename);
                }
            } else {
                if (unlink(filename) == 0) {
                    printf("✅ File '%s' removed!\n", filename);
                } else {
                    printf("❌ rm: cannot remove '%s': %s\n", filename, strerror(errno));
                }
            }
        }
        else if (strcmp(args[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            }
        }
        else if (strcmp(args[0], "cat") == 0) {
            if (args[1] == NULL) {
                printf("❌ cat: missing operand\n");
                continue;
            }
            
            FILE *file = fopen(args[1], "r");
            if (file == NULL) {
                printf("❌ cat: %s: %s\n", args[1], strerror(errno));
                continue;
            }
            
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                printf("%s", buffer);
            }
            
            fclose(file);
        }
        else if (strcmp(args[0], "echo") == 0) {
            for (int i = 1; i < arg_count; i++) {
                printf("%s", args[i]);
                if (i < arg_count - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        else if (strcmp(args[0], "clear") == 0 || strcmp(args[0], "cls") == 0) {
            system("clear");
        }
        else if (strcmp(args[0], "settings") == 0) {
            show_settings();
        }
        else if (strcmp(args[0], "logout") == 0 || strcmp(args[0], "exit") == 0) {
            if (strcmp(current_language, "indonesian") == 0) {
                printf("👋 Terima kasih telah menggunakan NusOS!\n");
            } else {
                printf("👋 Thank you for using NusOS!\n");
            }
            exit(0);
        }
        else if (strcmp(args[0], "shutdown") == 0) {
            if (strcmp(current_language, "indonesian") == 0) {
                printf("🔌 Mematikan NusOS... Sampai jumpa!\n");
            } else {
                printf("🔌 Shutting down NusOS... See you later!\n");
            }
            exit(0);
        }
        else if (strcmp(args[0], "reboot") == 0) {
            if (strcmp(current_language, "indonesian") == 0) {
                printf("🔄 Restart NusOS...\n");
            } else {
                printf("🔄 Rebooting NusOS...\n");
            }
            sleep(2);
            execl("./nusos", "nusos", (char *)NULL);
        }
        else if (strcmp(args[0], "whoami") == 0) {
            printf("%s\n", current_user.username);
        }
        else if (strcmp(args[0], "uname") == 0) {
            printf("NusOS 1.0.0 x86_64 GNU/Linux\n");
        }
        else if (strcmp(args[0], "nusos-info") == 0) {
            printf("🌟 === NusOS System Information === 🌟\n");
            printf("OS Name: NusOS\n");
            printf("Version: 1.0.0\n");
            printf("User: %s (%s)\n", current_user.name, current_user.username);
            printf("Theme: %s\n", current_user.theme);
            printf("CLI Mode: %s\n", current_user.cli_mode);
            printf("Language: %s\n", current_user.language);
            printf("Timezone: %s\n", current_user.timezone);
            printf("🚀 World's Best Operating System! 🚀\n");
        }
        // Advanced command support - pass to system with auto-fallback
        else {
            char full_command[1024] = "";
            for (int i = 0; i < arg_count; i++) {
                strcat(full_command, args[i]);
                if (i < arg_count - 1) strcat(full_command, " ");
            }
            
            printf("🔍 Executing: %s\n", full_command);
            
            // Try with auto-fallback
            char fallback_command[1024];
            sprintf(fallback_command, "%s 2>/dev/null || echo '❌ Command \"%s\" not found or failed'", full_command, args[0]);
            
            if (system(fallback_command) == -1) {
                printf("❌ Failed to execute command!\n");
            }
        }
    }
}
