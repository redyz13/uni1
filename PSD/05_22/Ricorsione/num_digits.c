#include <stdio.h>

int num_digits(int n) {
    if (n == 0) return 0;

    return 1 + num_digits(n / 10);
}

int main(void) {
    printf("Number of digits of 3568: %d", num_digits(3568));

    return 0;
}