#include <stdio.h>
#define SIZE 10 

void put_number(int a[], int k);
void print(int a[]);

int main() {
    int a[SIZE] = {0}, k;

    printf("Inserire un numero intero: ");
    scanf("%d", &k);

    put_number(a, k);

    print(a);

    return 0;
}

void put_number(int a[], int k) {
    int i = 0;

    while(k != 0) {
        a[k % 10] += 1;
        k /= 10;
    }
}

void print(int a[]) {
    int i;

    for(i = 0; i < SIZE; i++) {
        if(a[i] > 1) {
            printf("%d ", i);
        }
    }
}
