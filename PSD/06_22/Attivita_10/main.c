#include <stdio.h>
#include "btree.h"

int contaFoglie(Btree t);
Btree speculare(Btree t);
int max(Btree t);
int min(Btree t);

int main(void) {
    Btree h, a, d, l, o, q, c, p, s;

    h = newBtree();
    a = newBtree();
    d = newBtree();
    l = newBtree();
    o = newBtree();
    q = newBtree();
    c = newBtree();
    p = newBtree();
    s = newBtree();

    o = consBtree(8, NULL, NULL);
    q = consBtree(4, o, NULL);
    l = consBtree(5, NULL, NULL);
    d = consBtree(2, q, l);
    a = consBtree(9, NULL, NULL);
    s = consBtree(6, a, NULL);
    p = consBtree(7, NULL, NULL);
    c = consBtree(3, s, p);
    h = consBtree(1, d, c);

    printf("Albero:\n");
    preorder(h);

    printf("\n\nNumero di foglie: %d\n", contaFoglie(h));

    Btree new = newBtree();
    new = speculare(h);

    printf("\nAlbero speculare:\n");
    preorder(new);

    int massimo = max(new);
    printf("\n\nIl massimo è %d", massimo);
    
    int minimo = min(new);
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

int max(Btree t) {
    Item massimo, tmp;
    Item sx, dx;
    
    tmp = getItem(t);

    if (/*tmp != NULLITEM*/1)
        massimo = tmp;
    
    if (isEmpty(t)) return massimo;

    sx = max(figlioSX(t));
    dx = max(figlioDX(t));

    if(massimo < sx)
        massimo = sx;

    if(massimo < dx)
        massimo = dx; 

    return massimo;
}

int min(Btree t) {
    Item minimo, tmp;
    Item sx, dx;
    
    tmp = getItem(t);

    if (tmp != NULLITEM)
        minimo = tmp;
    
    if (isEmpty(t)) return minimo;

    sx = max(figlioSX(t));
    dx = max(figlioDX(t));

    if(minimo > sx)
        minimo = sx;

    if(minimo > dx)
        minimo = dx; 

    return minimo;
}
