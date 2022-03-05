#include <stdio.h>

int main() {
    int n, i, star = 1;

    printf("Inserire il numero di righe: ");
    scanf("%d", &n);

    while(n > 0) {
        for(i = 0; i < n - 1; i++)
            printf(" ");

        for(i = 0; i < star; i++) {
            printf("*");
        }

        star += 2;
        n--;
        printf("\n");
    }
}
