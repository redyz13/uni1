#include <stdio.h>
#include "util.h"

BST creaBST(void);

int main(void) {
    BST bst = creaBST();

    printf("\nAlbero binario di ricerca:\n");

    print2D(bst);
    
    putchar('\n');

    printf("\nNodi dell'albero da 5 a 30: ");

    nodi_intervallo(bst, 5, 30);

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
    if (i == size) return;

    inserisciArray(figlioSX(t), arr, size);
    arr[i] = getItem(t);
    i++;
    inserisciArray(figlioDX(t), arr, size);
}

void nodiIntervallo(BST t, Item a, Item b) {
    if (a > b) return;
    Item arr[NODES];
    int size = sizeof(arr) / sizeof(*arr);

    inserisciArray(t, arr, size);

    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] == a)
            break;
    }

    if (arr[i] != a) return;

    while (i < size) {
        printItem(arr[i]);
        putchar(' ');

        i++;

        if (arr[i] == b) {
            printItem(arr[i]);
            break;
        }
    }
}

void nodi_intervallo(BST t, Item a, Item b) {
    if (t == NULL) return;

    if (isMinus(a, getItem(t))) {
        nodi_intervallo(figlioSX(t), a , b);
    }

    printItem(getItem(t));
    putchar(' ');

    if (isMinus(getItem(t), b)) {
        nodi_intervallo(figlioDX(t), a , b);
    }
}
