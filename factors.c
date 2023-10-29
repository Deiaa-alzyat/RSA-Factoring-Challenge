#include <stdio.h>
#include <stdlib.h>

// Function to factorize a number into two smaller numbers
void factorize(long long n) {
    for (long long i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%lld=%lld*%lld\n", n, n / i, i);
            return; // Stop after the first factorization
        }
    }
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
    while (fgets(line, sizeof(line), file) != NULL) {
        long long n = atoll(line);
        if (n > 1) {
            factorize(n);
        }
    }

    fclose(file);
    return 0;
}
