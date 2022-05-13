#include <stdio.h>

int sum_digits(int n) {
    if (n == 0) return 0;

    return n % 10 + sum_digits(n / 10);
}

int main(void) {
    printf("Sum of digits of 3568: %d", sum_digits(3568));

    return 0;
}