#include <stdio.h>
#include <math.h>

long pthFactor(long n, long p) {
    if (p <= 0) return 0;
    
    long count = 0;
    long sqrt_n = (long)sqrt(n);
    
    for (long i = 1; i <= sqrt_n; i++) {
        if (n % i == 0) {
            count++;
            if (count == p) return i;
        }
    }
    
    for (long i = sqrt_n; i >= 1; i--) {
        if (n % i == 0) {
            long paired = n / i;
            if (paired != i) {
                count++;
                if (count == p) return paired;
            }
        }
    }
    
    return 0;
    // return -1; // If you want to return -1 instead of 0 when p is out of range
}