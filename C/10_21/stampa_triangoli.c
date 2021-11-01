#include <stdio.h>

int main() {
    int n, star = 1;

    printf("Inserire il numero di righe: ");
    scanf("%d", &n);

    while(n > 0) {
        for(int i = 0; i < n - 1; i++)
            printf(" ");

        for(int i = 0; i < star; i++) {
            printf("*");
        }

        star += 2;
        n--;
        printf("\n");
    }
}
