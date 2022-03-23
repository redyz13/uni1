#include <stdlib.h>
#include "op_matrici.h"

int **crea_matrice(int *a, int m, int n) {
    int **matrix;
    int i, j;

    matrix = malloc(sizeof(int) * (m * n));

    if(!matrix) {
        return NULL;
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            matrix[i][j] = a[i];
        }
    }

    return matrix;
}

int **somma_matrici(int **a, int **b, int m, int n) {
    int **somma;
    int i, j;

    somma = malloc(sizeof(int) * (m * n));

    if(!somma) {
        return NULL;
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            somma[i][j] = (a[i][j] + b[i][j]); 
        }
    }

    return somma;
}

/*int **prodotto(int **a, int **b, int m, int n) {
    int **prodotto;
    int i, j;

    prodotto = malloc(sizeof(int) * (m * n));

    if(!prodotto) {
        return NULL;
    }
}*/
