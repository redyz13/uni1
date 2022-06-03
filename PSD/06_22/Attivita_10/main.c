#include <stdio.h>
#include "btree.h"

int contaFoglie(Btree t);
Btree speculare(Btree t);

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

    o = consBtree('o', NULL, NULL);
    q = consBtree('q', NULL, NULL);
    l = consBtree('l', o, q);
    d = consBtree('d', NULL, NULL);
    a = consBtree('a', d, l);
    s = consBtree('s', NULL, NULL);
    p = consBtree('p', NULL, NULL);
    c = consBtree('c', p, s);
    h = consBtree('h', a, c);

    preorder(h);

    putchar('\n');

    printf("\nNumero di foglie: %d\n", contaFoglie(h));

    Btree new = newBtree();
    new = speculare(h);

    putchar('\n');

    preorder(new);

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
