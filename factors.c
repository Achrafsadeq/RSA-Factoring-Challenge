#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Factorize function optimized for fast factorization
void factorize(unsigned long long n) {
    unsigned long long i;
    unsigned long long q, p;

    // Try finding the smallest factor from 2 up to sqrt(n)
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;

            // Print q (larger factor) first, then p (smaller factor)
            printf("%llu=%llu*%llu\n", n, q, p);
            return;
        }
    }

    // If no factor is found, the number is prime or 1
    printf("%llu=%llu*1\n", n, n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    unsigned long long number;

    // Read each line from the file (using fast fgets and conversion)
    while (fgets(line, sizeof(line), file)) {
        number = strtoull(line, NULL, 10);  // Convert the line to an unsigned long long
        factorize(number);  // Factorize the number
    }

    fclose(file);
    return 0;
}
