#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(void) {
    Btree a = createBtree();

    printf("Stampa dell'albero:\n");
    print2D(a);
    
    printf("\nL'altezza del'albero è: %d", getAltezza(a));

    printf("\nL'albero è bilanciato: %d", isBilanciato(a));

    printf("\nHeap: %d\n", isHeap(a));

    return 0;
}

Btree createBtree(void) {
    Btree a, b, c, d, e, f, g, h;

    a = newBtree();
    b = newBtree();
    c = newBtree();
    d = newBtree();
    e = newBtree();
    f = newBtree();
    h = newBtree();

    e = consBtree(7, NULL, NULL);
    f = consBtree(6, NULL, NULL);
    g = consBtree(5, NULL, NULL);
    h = consBtree(1, NULL, NULL);
    d = consBtree(8, NULL, h);
    b = consBtree(9, d, e);
    c = consBtree(9, f, g);
    a = consBtree(10, b, c);

    return a;
}

int getAltezza(Btree t) {
    if (t == NULL) return 0;

    int altezza_sx = 1 + getAltezza(figlioSX(t));
    int altezza_dx = 1 + getAltezza(figlioDX(t));

    return (altezza_sx > altezza_dx) ? altezza_sx : altezza_dx;
}

int isBilanciato(Btree t) {
    if(t == NULL) return 1;

    int sx = isBilanciato(figlioSX(t));
    int dx = isBilanciato(figlioDX(t));

    int diff = getAltezza(figlioSX(t)) - getAltezza(figlioDX(t));

    if (diff < 0) 
        diff *= -1;
    
    return sx && dx && (diff <= 0);
}

int isComplete(Btree t) {
    if (t == NULL) return 1;

    Queue q = newQueue();
    Btree tmp;
    enqueue(q, t);
    int flag = 0;

    while (!isEmptyQueue(q)) {
        tmp = dequeue(q);

        if (figlioSX(tmp) != NULL) {
            if (flag == 1) return 0;
            enqueue(q, figlioSX(tmp));
        }
        else {
            flag = 1;
        }
        if (figlioDX(tmp) != NULL) {
            if (flag == 1) return 0;
            enqueue(q, figlioDX(tmp));
        }
        else {
            flag = 1;
        }
    }

    return 1;
}

int isMaxTree(Btree t) {
    if (t == NULL) return 1;

    if (isMinus(getItem(t), getItem(figlioSX(t))) ||
        isMinus(getItem(t), getItem(figlioDX(t)))) {
        return 0;
    }

    return isMaxTree(figlioSX(t)) && isMaxTree(figlioDX(t));
}

int isHeap(Btree t) {
    return isComplete(t) && isMaxTree(t);
}
