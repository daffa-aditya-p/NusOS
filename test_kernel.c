#include "include/nusos.h"

int main() {
    printf("Testing kernel functions directly...\n");
    
    // Initialize kernel first
    init_nusos_kernel();
    
    printf("\n=== Testing show_kernel_info ===\n");
    show_kernel_info();
    
    printf("\n=== Testing show_performance_stats ===\n");
    show_performance_stats();
    
    printf("\n=== Testing security status ===\n");
    printf("Security Level: %d\n", sys_config.security_level);
    printf("Encryption Enabled: %d\n", sys_config.encryption_enabled);
    
    return 0;
}
