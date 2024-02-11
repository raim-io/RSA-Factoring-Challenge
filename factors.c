#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_factors(uint64_t n) {
    // Handle even numbers quickly
    if (n % 2 == 0) {
        printf("%lu=2*%lu\n", n, n / 2);
        return;
    }

    // Only iterate through odd numbers starting from 3
    for (uint64_t p = 3; p * p <= n; p += 2) {
        if (n % p == 0) {
            printf("%lu=%lu*%lu\n", n, p, n / p);
            return;
        }
    }

    // If no factors found, print n itself (shouldn't happen with given constraints)
    printf("%lu=%lu*1\n", n, n);
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
