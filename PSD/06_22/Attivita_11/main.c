#include <stdio.h>
#include "util.h"

BST creaBST(void);

int main(void) {
    BST bst = creaBST();

    printf("\nAlbero binario di ricerca:\n");

    print2D(bst);
    
    printf("\nAlbero ordinato: ");

    Item arr[NODES];
    int size = sizeof(arr) / sizeof(*arr);

    inserisciArray(bst, arr, size);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    putchar('\n');

    return 0;
}

BST creaBST(void) {
    Item bst[NODES] = { 20, 10, 5, 3, 6, 15, 30, 25, 40, 35 };

    BST new = newBST();

    for (int i = 0; i < NODES; i++)
        new = insertNode(new, bst[i]);

    return new;
}

int isBST(Btree t) {
    if (t == NULL) return 1;

    if (!isEmpty(figlioSX(t))) {
        if (!(isMinus(getItem(figlioSX(t)), getItem(t)))) {
            return 0;
        }
    }

    if (!isEmpty(figlioDX(t))) {
        if (!(isMinus(getItem(t), getItem(figlioDX(t))))) {
            return 0;
        }
    }
   
    return isBST(figlioSX(t)) && isBST(figlioDX(t));
}

void inserisciArray(BST t, Item *arr, int size) {
    static int i = 0;
    if (t == NULL) return;

    inserisciArray(figlioSX(t), arr, size);
    arr[i] = getItem(t);
    i++;
    inserisciArray(figlioDX(t), arr, size);
}
