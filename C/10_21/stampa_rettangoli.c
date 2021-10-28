#include <stdio.h>

void stampa_rettangolo_eroinomane(int n, int m);

int main() {
    int n, m;

    do {
        printf("Inserire il lato del rettangolo: ");
        scanf("%d", &n);
    }
    while(n < 0);

    do {
        printf("Inserire il secondo lato del rettangolo: ");
        scanf("%d", &m);
    }
    while(n < 0);

    stampa_rettangolo_eroinomane(n, m);

    return 0;
}

void stampa_rettangolo_eroinomane(int n, int m) {
    int i = 0;
    int k = m;

    printf("\n[Rettangolo eroinomane]\n");

    for(; m > 0; m--) {
        if(m == k || m == 1) {
            for(; i < n; i++)
                printf("*");
        }
        else {
            for(; i < n; i++) {
                if(i == n - 1 || i == 0)
                    printf("*");
                else
                    printf(" ");        
            }
        }
        
        printf("\n");
        i = 0;
    }
}
