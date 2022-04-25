#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int main(void) {
    Queue q;
    Queue q1, q2, q3, q4, concat;
    float lun;

    q = newQueue();

    printf("Creazione punti:\n");
    creaPunti(q);

    q1 = newQueue(); 
    q2 = newQueue(); 
    q3 = newQueue(); 
    q4 = newQueue(); 
    
    // Dealloca q
    sottocode(q, q1, q2, q3, q4);
    
    lun = spezzata(q1);

    printf("\nLa lunghezza della spezzata del primo quadrante è %.2f\n", lun);

    // Le sottocode passate vengono deallocate
    concat = concatena(q3, q4);
    concat = concatena(q2, concat);
    concat = concatena(q1, concat);

    printf("\nCoda concatenata in ordine discendente di quadrante:\n\n");

    printQueue(concat);

    destroyQueue(concat);

    return 0;
}

int creaPunti(Queue q) {
    Punto p;
    float x, y;
    int i = 0;
    char s;

    do {
        printf("\nCreazione del punto %d\n", i++);

        printf("\nInserisci ascissa: ");
        scanf("%f", &x);
        printf("Inserisci ordinata: ");
        scanf("%f", &y);

        p = creaPunto(x, y);
        if(p == NULL) return 0;

        enqueue(q, p);

        printf("\nVuoi inserire altri punti (s/n): ");
        getchar();
        s = getchar();

        putchar('\n');
    } while(s != 'n');

    return 1;
}

int getQuadrante(Punto p) {
    if(p == NULL) return 0;

    float x, y;

    x = getAscissa(p);
    y = getOrdinata(p);

    /* Tutte le coordinate aventi uno zero faranno
    *  parte del quadrante positivo
    */
    if(x >= 0 && y >= 0) return 1;
    if(x >= 0 && y < 0) return 2;
    if(x < 0 && y < 0) return 3;
    if(x < 0 && y >= 0) return 4;

    return -1;
}

int sottocode(Queue q, Queue q1, Queue q2, Queue q3, Queue q4) {
    if(q == NULL) return 0;

    int quadrante;
    Punto p;

    while(!isEmpty(q)) {
        p = dequeue(q);
        if(p == NULL) return 0;

        quadrante = getQuadrante(p);

        switch(quadrante) {
            case 1:
                enqueue(q1, p);
                break;
            case 2:
                enqueue(q2, p);
                break;
            case 3:
                enqueue(q3, p);
                break;
            case 4:
                enqueue(q4, p);
                break;
        }
    }

    freeQueue(q);

    return 1;
}

float spezzata(Queue q) {
    Queue tmp;
    Punto p1, p2;
    float somma = 0;

    tmp = newQueue();
    
    p1 = dequeue(q);
    enqueue(tmp, p1);

    while(!isEmpty(q)) {
        p2 = dequeue(q);
        enqueue(tmp, p2);

        somma += distanza(p1, p2);

        p1 = p2;
    }

    while(!isEmpty(tmp)) {
        enqueue(q, dequeue(tmp));
    }

    freeQueue(tmp);

    return somma;
}

Queue concatena(Queue q1, Queue q2) {
    Queue new = newQueue();

    // Se almeno una coda esiste, la concatenazione
    // avviene comunque

    while(!isEmpty(q2)) {
        enqueue(new, dequeue(q2));
    }

    while(!isEmpty(q1)) {
        enqueue(new, dequeue(q1));
    }

    freeQueue(q1);
    freeQueue(q2);

    return new;
}
