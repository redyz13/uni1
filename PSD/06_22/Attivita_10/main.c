#include <stdio.h>
#include <limits.h>
#include "btree.h"

int contaFoglie(Btree t);
Btree speculare(Btree t);
Item max(Btree t);
Item min(Btree t);

int main(void) {
    Btree a, b, c, d, e, f, g;

    a = newBtree();
    b = newBtree();
    c = newBtree();
    d = newBtree();
    e = newBtree();
    f = newBtree();

    d = consBtree(8, NULL, NULL);
    e = consBtree(15, NULL, NULL);
    f = consBtree(6, NULL, NULL);
    g = consBtree(12, NULL, NULL);
    b = consBtree(9, d, e);
    c = consBtree(11, f, g);
    a = consBtree(10, b, c);

    printf("Albero:\n");
    preorder(a);

    printf("\n\nNumero di foglie: %d\n", contaFoglie(a));

    Btree new = newBtree();
    new = speculare(a);

    printf("\nAlbero speculare:\n");
    preorder(new);

    int massimo = max(a);
    printf("\n\nIl massimo è %d", massimo);
    
    int minimo = min(a);
    printf("\nIl minimo è %d\n", minimo);

    return 0;
}

int contaFoglie(Btree t) {
    if (isEmpty(t)) return 0;

    if (isEmpty(figlioSX(t)) && isEmpty(figlioDX(t))) {
        return 1;
    }

    return contaFoglie(figlioSX(t)) + contaFoglie(figlioDX(t));
}

Btree speculare(Btree t) {
    if (isEmpty(t)) return t;

    return consBtree(getItem(t), speculare(figlioDX(t)), speculare(figlioSX(t)));
}

Item max(Btree t) {
    Item massimo;
    Item sx, dx;
     
    if (isEmpty(t)) return INT_MIN;

    massimo = getItem(t);

    sx = max(figlioSX(t));
    dx = max(figlioDX(t));

    if (massimo < sx)
        massimo = sx;

    if (massimo < dx)
        massimo = dx; 

    return massimo;
}

Item min(Btree t) {
    Item minimo;
    Item sx, dx;
    
    if (isEmpty(t)) return INT_MAX;

    minimo = getItem(t);

    sx = min(figlioSX(t));
    dx = min(figlioDX(t));

    if (minimo > sx)
        minimo = sx;

    if (minimo > dx)
        minimo = dx; 

    return minimo;
}
