#include <stdio.h>

// Function to check if a number is prime
int is_prime(long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to find and print prime factors
void find_prime_factors(long long n) {
    for (long long i = 2; i <= n; i++) {
        if (n % i == 0 && is_prime(i)) {
            long long j = n / i;
            if (is_prime(j)) {
                printf("%lld=%lld*%lld\n", n, j, i);
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    long long n;
    if (fscanf(file, "%lld", &n) != 1) {
        printf("Error reading the number from the file\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    if (n < 2) {
        printf("The input number must be greater than or equal to 2.\n");
        return 1;
    }

    if (is_prime(n)) {
        printf("%lld is a prime number.\n", n);
    } else {
        find_prime_factors(n);
    }

    return 0;
}
