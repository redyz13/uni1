#include <stdio.h>
#define N 100

/* Programma che dato un array di N numeri dati input e un numero k dato in input:
*  Scambia i numeri con i numeri delle celle di -k posizioni.
*  Se con la sottrazione si esce fuori dall'array, la posizione del numero sarà
*  scambiata al posto di quella del numero dell'ultima cella e viceversa
*/  

int main() {
    int a[N], k, i = 0, j;
    int temp, kk;

    printf("Inserire k: ");
    scanf("%d", &k);

    kk = k;

    do {
        printf("\nInserire l'elemento %d dell'array [-1 per uscire]: ", i);
        scanf("%d", &temp);
        if(temp != -1)
            a[i++] = temp; 
        else
            break;
    } while(1);

    for(j = 0; j <= i; j++) {
        if(kk > 0) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp; 
        }
        else {
            temp = a[j-k];
            a[j-k] = a[j];
            a[j] = temp;
        }

        kk--;
    }

    printf("\nRisultato Array = { ");

    for(j = 0; j < i; j++) {
        printf("%d  ", a[j]);
    }

    printf("}\n");

    return 0;
}
