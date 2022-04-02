#include <stdio.h>

int ricerca_binaria(int arr[], int inf, int sup, int x);
  
int main(void) {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Inserire un numero da cercare: ");
    scanf("%d", &x);

    int result = ricerca_binaria(arr, 0, n - 1, x);

    (result == -1) ? printf("Elemento non presente nell'array\n")
                   : printf("Elemento presente alla posizione: %d\n", result);
    return 0;
}

int ricerca_binaria(int arr[], int inf, int sup, int x) {
    int mid;

    while (inf <= sup) {
        mid = inf + (sup - inf) / 2;
  
        // Controlla se è presente al centro
        if (arr[mid] == x) {
            return mid;
        }
  
        // Se x è maggiore, ignora la parte sinistra
        if (arr[mid] < x) {
            inf = mid + 1;
        }
  
        // Se x è minore, ignora la parte destra
        else {
            sup = mid - 1;
        }
    }
  
    // Ritorna -1 se l'elemento non è presente
    return -1;
}
