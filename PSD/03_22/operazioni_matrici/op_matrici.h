#ifndef _op_matrici_h_
#define _op_matrici_h_

/* Crea una matrice mxn che ha come valori i numeri
 * presenti nella sequenza di input (l'array dato come
 * parametro) e la restituisce
*/
int **crea_matrice(int *a, int m, int n);

/* Date due matrici e la loro dimensione, restituisce una matrice
 * che è la somma delle due
*/
int **somma_matrici(int **a, int **b, int m, int n);

/* Date due matrici e la loro dimensione, restituisce una matrice
 * che è il prodotto interno tra le due (righe * colonne)
*/
int **prodotto(int **a, int **b, int m, int n);

#endif
