#include <stdio.h>
#include <math.h>

/**
 * Find the p-th smallest factor of n
 * Optimized for n up to 10^15 and p up to 10^9
 * Time complexity: O(sqrt(n))
 * Space complexity: O(1)
 */
long pthFactor(long n, long p) {
    // Edge case: invalid p
    if (p <= 0) return 0;
    
    long count = 0;
    long sqrt_n = (long)sqrt(n);
    
    // Find factors <= sqrt(n)
    for (long i = 1; i <= sqrt_n; i++) {
        if (n % i == 0) {
            count++;
            if (count == p) {
                return i;
            }
        }
    }
    
    // Find factors > sqrt(n) (the paired factors)
    for (long i = sqrt_n; i >= 1; i--) {
        if (n % i == 0) {
            long paired = n / i;
            if (paired != i) {  // Skip perfect square duplicate
                count++;
                if (count == p) {
                    return paired;
                }
            }
        }
    }
    
    return 0;  // Not enough factors
}

// Test code - remove or comment out for final submission
#ifdef TEST_MODE
int main() {
    // Test case 1
    long result = pthFactor(10, 3);
    printf("pthFactor(10, 3) = %ld (Expected: 5)\n", result);
    
    // Test case 2
    result = pthFactor(10, 10);
    printf("pthFactor(10, 10) = %ld (Expected: 0)\n", result);
    
    // Test case 3
    result = pthFactor(16, 5);
    printf("pthFactor(16, 5) = %ld (Expected: 16)\n", result);
    
    return 0;
}
#endif