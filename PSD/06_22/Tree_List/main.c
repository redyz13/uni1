#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "list.h"

Btree createBtree(void);
void treeList(Btree t, int i, int altezza, List l);

int main(void) {
    Btree a = createBtree();

    printf("Stampa dell'albero:\n");
    print2D(a);

    List l = newList();

    treeList(a, 1, 3, l);

    printf("Lista:\n");
    printList(l);

    return 0;
}

Btree createBtree(void) {
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

    return a;
}

void treeList(Btree t, int i, int altezza, List l) {
    if (i > altezza) return;

    if (i % 2 == 0) {
        addFirst(l, getItem(t));
    }

    treeList(figlioSX(t), i + 1, altezza, l);
    treeList(figlioDX(t), i + 1, altezza, l);
}
