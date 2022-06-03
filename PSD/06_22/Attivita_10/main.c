#include <stdio.h>
#include "btree.h"

int main(void) {
    Btree r, sx, dx;

    sx = newBtree();
    dx = newBtree();
    sx = consBtree(10, NULL, NULL);
    dx = consBtree(20, NULL, NULL);

    r = newBtree();
    r = consBtree(30, sx, dx);

    inorder(r);

    putchar('\n');

    return 0;
}
