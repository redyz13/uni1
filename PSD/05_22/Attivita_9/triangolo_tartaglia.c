#include <stdio.h>

int tartaglia(int r, int c) {
    if (c == 1) return 1;
    if (r == c) return 1;

    return (tartaglia(r - 1, c - 1) + tartaglia(r - 1, c));
}

int main(void) {
    printf("(5,2): %d\n", tartaglia(5, 2));

    return 0;
}
