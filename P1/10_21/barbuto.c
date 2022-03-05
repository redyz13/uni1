#include <stdio.h>

int main() {
    int i;

    for(i = 1; i <= 10; i++)
        printf("%d è %spari\n", i, i % 2 == 0 ? "" : "dis");

    printf("\n");

    return 0;
}
