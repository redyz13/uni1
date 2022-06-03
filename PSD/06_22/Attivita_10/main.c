#include <stdio.h>
#include "btree.h"

int main(void) {
    Btree t;

    t = newBtree();
    t = consBtree(10, NULL, NULL);

    return 0;
}
