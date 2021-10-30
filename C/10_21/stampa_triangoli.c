#include <stdio.h>

int main() {
    int n, ws, star = 1;

    printf("Inserire il numero di righe: ");
    scanf("%d", &n);

    ws = n - 1;

    while(n > 0) {
        if(n > 1) {
            for(int i = 0; i < ws; i++)
                printf(" ");
        }

        for(int i = 0; i < star; i++) {
            printf("*");
        }

        star += 2;
        ws--;
        n--;
        printf("\n");
    }
}
