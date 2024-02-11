#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to find and print factorization
void print_factors(uint64_t n) {
    uint64_t p, q;

    for (p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            q = n / p;
            printf("%lu=%lu*%lu\n", n, p, q);
            return;
        }
    }

    // If no factors found, print n=1*n
    printf("%lu=1*%lu\n", n, n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    uint64_t number;
    while (fscanf(file, "%lu", &number) != EOF) {
        print_factors(number);
    }

    fclose(file);
    return 0;
}
