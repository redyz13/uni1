#include <stdio.h>
#define NMAX 100

/*
* Trova i numeri di Armstrong
* a 3 cifre
*/

int leggiVett (int A[]);
int azzera_no_Arm(int A[], int n);
int isArmstrong (int k);
int sommacubi_cifre(int k);
void stampa_non_null(int A[], int n);

int main() {
    int A[NMAX], n, array_finale;

    n = leggiVett(A);

    array_finale = azzera_no_Arm(A, n);
    
    printf("\nRisultato:\n");

    stampa_non_null(A, array_finale);

    printf("\n");
}

int leggiVett (int A[]) {
    int i = 0, temp;
    
    while(666) {
        printf("Inserisci il valore %d dell'array: ", i);
        scanf("%d", &temp);
        if(temp != -1) {
            A[i] = temp;
            i++;
        }
        else {
            return i;
        }
    }
}

int sommacubi_cifre(int k) {
    int i = 0, f = 0, y = 0;
    
    while(k != 0) {
        y = k % 10;
        f += (y * y * y); 
        k /= 10;
        i++;
    }
    
    return f;
}

int isArmstrong(int k) {
    int f;

    if(k >= 100 && k <= 999) {
        f = sommacubi_cifre(k);
        
        if (f != k) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

int azzera_no_Arm(int A[], int n) {
    int i;
    
    for(i = 0; i < n; i++) {
        if(!isArmstrong(A[i])) {
            A[i] = 0;
        }
    }

    return n;
}

void stampa_non_null(int A[], int n) {
    int i;

    for(i = 0; i < n; i++) {
        if(A[i] != 0)
            printf("%d ", A[i]);
    }
}
