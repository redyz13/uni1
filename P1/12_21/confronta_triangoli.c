#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
    float z;
} triangolo;

triangolo *alloca(triangolo *t);
void inserisci_lati(triangolo *t);
void ordina(triangolo *t);
int confronta(const triangolo *t1, const triangolo *t2);

int main() {
    triangolo *t1, *t2;

    printf("Triangolo 1:\n\n");

    t1 = alloca(t1);
    inserisci_lati(t1);
    ordina(t1);

    printf("\nTriangolo 2:\n\n");

    t2 = alloca(t2);
    inserisci_lati(t2);
    ordina(t2);

    if(confronta(t1, t2)) {
        printf("\nI due triangolo sono uguali\n");
    }
    else {
        printf("\nI due triangolo sono diversi\n");
    }

    return 0;
}

triangolo *alloca(triangolo *t) {
    t = malloc(sizeof(triangolo));

    if(!t) {
        return NULL;
    }

    return t;
}

void inserisci_lati(triangolo *t) {
    printf("Inserire il primo lato: ");
    scanf("%f", &t->x);
    printf("Inserire il secondo lato: ");
    scanf("%f", &t->y);
    printf("Inserire il terzo lato: ");
    scanf("%f", &t->z);
}

void ordina(triangolo *t) {
    float tmp;
    float arr[3];
    int i, j;

    arr[0] = t->x;
    arr[1] = t->y;
    arr[2] = t->z;
    
    for(i = 3 - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    t->x = arr[0];
    t->y = arr[1];
    t->z = arr[2];
}

int confronta(const triangolo *t1, const triangolo *t2) {
    if((t1->x == t2->x) && (t1->y == t2->y) &&
       (t1->z == t2->z)
    )
        return 1;
    else
        return 0;
}
