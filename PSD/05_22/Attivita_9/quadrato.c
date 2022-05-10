#include <stdio.h>

/*
    Precondizioni:
        1. n >= 1
*/
int quadrato(int n) {
    if (n == 1) return 1;

    return ((2 * n - 1) + (quadrato(n - 1)));
}

int main(void) {
    printf("Quadrato di 5: %d\n", quadrato(5));

    return 0;
}