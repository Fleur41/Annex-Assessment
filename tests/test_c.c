#include <stdio.h>
#include "pth_factor.c"

int main() {
    // Test 1
    printf("Test 1: %ld\n", pthFactor(10, 3));  // Expected: 5
    
    // Test 2
    printf("Test 2: %ld\n", pthFactor(10, 10)); // Expected: 0
    
    // Test 3
    printf("Test 3: %ld\n", pthFactor(16, 4));  // Expected: 8
    
    return 0;
}