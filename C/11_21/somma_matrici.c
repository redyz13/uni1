#include <stdio.h>
#define RMAX 30
#define CMAX 30

void read_matrix(int a[][CMAX], int nr, int nc);
void print_matrix(int a[][CMAX], int nr, int nc);
int sum_matrix(int a[][CMAX], int nr, int nc);

int main() {
    int a[RMAX][CMAX];
    int nr, nc;

    printf("Inserire il numero di righe della matrice: ");
    scanf("%d", &nr);
    printf("Inserire il numero di colonne della matrice: ");
    scanf("%d", &nc);

    read_matrix(a, nr, nc);
    print_matrix(a, nr, nc);

    printf("\n\nSum = %d", sum_matrix(a, nr, nc));
}

void read_matrix(int a[][CMAX], int nr, int nc) {
    int i, j;

    for(i = 0; i < nr; i++) {
        for(j = 0; j < nc; j++) {
            printf("\nMatrice [%d][%d] =  ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void print_matrix(int a[][CMAX], int nr, int nc) {
    int i, j;

    for(i = 0; i < nr; i++) {
        printf("\n");
        for(j = 0; j < nc; j++) {
            printf("%d\t", a[i][j]);
        }
    }
}

int sum_matrix(int a[][CMAX], int nr, int nc) {
    int i, j, sum = 0;

    for(i = 0; i < nr; i++) {
        for(j = 0; j < nc; j++) {
            sum += a[i][j];
        }
    }

    return sum;
}
