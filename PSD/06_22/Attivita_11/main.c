#include <stdio.h>
#include "util.h"

BST creaBST(void);

int main(void) {
    BST t = creaBST();

    printf("Albero binario di ricerca:\n");

    print2D(t);

    return 0;
}

BST creaBST(void) {
    Item bst[NODES] = { 20, 10, 5, 3, 6, 15, 30, 25, 40, 35 };

    BST new = newBST();

    for (int i = 0; i < NODES; i++)
        new = insertNode(new, bst[i]);

    return new;
}
