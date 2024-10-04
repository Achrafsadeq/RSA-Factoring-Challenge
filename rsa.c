#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * Function to check if a number is prime
 */
int is_prime(long long num) {
    if (num <= 1) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

/**
 * Function to find the factors of n
 */
void find_factors(long long n) {
    long long i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            long long factor1 = i;
            long long factor2 = n / i;
            if (is_prime(factor1) && is_prime(factor2)) {
                printf("%lld=%lld*%lld\n", n, factor1, factor2);
                return;
            }
        }
    }
    printf("Factors not found for %lld\n", n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open file with number
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Read the number from the file
    long long n;
    if (fscanf(file, "%lld", &n) != 1) {
        perror("Error reading number");
        fclose(file);
        return 1;
    }

    fclose(file);

    // Find and print the factors
    find_factors(n);

    return 0;
}
