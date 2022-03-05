#include <stdio.h>
#define SIZE 30

/*
 * Programma che inserisce in un array b 
 * i valori di un array a senza valori ripetuti 
*/

int get_dim(int min, int max);
void read_array(int a[], int n);
int compatta(int a[], int b[], int n);
void print_array(int a[], int);
int presente(int a[], int n, int k);

int main() {
    int a[SIZE], b[SIZE];
    int n, newsize;

    n = get_dim(0, 20);
    read_array(a, n);
    newsize = compatta(a, b, n);

    printf("\n[Array Compattato]\n");

    print_array(b, newsize);

    return 0;
}

int get_dim(int min, int max) {
    int x;

    do {
        printf("Inserisci la dimensione dell' array: ");
        scanf("%d", &x);
    } while(x < min || x > max);

    return x;
}

void read_array(int arr[], int lenght) {
    int i;

    for(i = 0; i < lenght; i++) {
        printf("\nInserisci il numero %d dell'array: ", i);
        scanf("%d", &arr[i]);
    }
}

// Metodo brutto (refactoring in basso ~by masta5)

/*int compatta(int a[], int b[], int n) {
    int i, j, temp, newsize = 0;
    int flag;

    for(i = 0; i < n; i++) {
        flag = 1;
        temp = a[i];

        for(j = i + 1; j < n; j++) {
            if(a[j] == temp) {
                flag = 0;
                break;
            }
        }

        if(flag) {
            b[newsize] = temp;
            newsize++;
        }
    }

    return newsize;
}*/

int compatta(int a[], int b[], int n) {
    int i, j = 1;

    b[0] = a[0];

    for(i = 1; i < n; i++) {
        if(!presente(b, j, a[i])) {
            b[j] = a[i];
            j++;
        }
    }

    return j;
}

int presente(int a[], int n, int k) {
    int i;

    for(i = 0; i < n; i++) {
        if(a[i] == k) {
            return 1;
        }
    }

    return 0;
}

void print_array(int arr[], int lenght) {
    int i;

    for(i = 0; i < lenght; i++)
        printf("\nNumero %d dell'array = %d\n", i, arr[i]);
}
