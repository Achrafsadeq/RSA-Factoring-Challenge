#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorize(unsigned long long int n) {
    unsigned long long int i, p, q;

    // Check for smallest factor p
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;

            // Ensure that q is the larger factor and p is the smaller one
            if (q < p) {
                unsigned long long int temp = p;
                p = q;
                q = temp;
            }

            printf("%llu=%llu*%llu\n", n, q, p);  // Print q first, then p
            return;
        }
    }
    // If no factors found (this could mean n is a prime number)
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
    unsigned long long int number;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Convert line to an unsigned long long int
        number = strtoull(line, NULL, 10);

        // Factorize the number
        factorize(number);
    }

    fclose(file);
    return 0;
}

