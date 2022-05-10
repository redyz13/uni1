#include <stdio.h>

/*
    Precondizioni:
        1. m > n
*/
int mcd(int m, int n) {
    if (m == n) return m;

    if (m > n)
        mcd(m - n, n);
    else
        mcd(m, n - m);
}

int main(void) {
    printf("MCD tra 494 e 130: %d\n", mcd(494, 130));

    return 0;
}
