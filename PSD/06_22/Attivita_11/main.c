#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(void) {
    BST bst = creaBST();

    printf("\nAlbero binario di ricerca:\n");

    print2D(bst);
    
    putchar('\n');

    printf("\nNodi dell'albero da 5 a 30: ");

    nodi_intervallo(bst, 5, 30);

    printf("\nLivelli: %d\n", getLivello(bst));
    
    Queue q = newQueue();

    printf("Nodi al livello 3: ");
    nodiAltezza(bst, q, 3, 1);
    
    BST node; 

    while(!isEmptyQueue(q)) {
        node = dequeue(q);
        printItem(getItem(node));
        putchar(' ');
    }

    printf("\nNumero di nodi: %d", contaNodi(bst));
    printf("\nMediano: %d", isMediano(bst, 5));
    
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

BST arrToBST(BST t, int *arr, int size, int i) {
    int mid = ((i + size) / 2);

    if (i >= size) return t; 
    
    t = insertNode(t, arr[mid]);

    t = arrToBST(t, arr, i, mid);
    t = arrToBST(t, arr, mid + 1, size);
    return t;
}

int getLivello(BST t) {
    if (t == NULL) return 0;

    int liv_dx, liv_sx;

    liv_dx = getLivello(figlioDX(t));
    liv_sx = getLivello(figlioSX(t));

    if (liv_dx < liv_sx) {
        return 1 + liv_sx;
    }
    else {
        return 1 + liv_dx;
    }
}

void nodiAltezza(BST t, Queue q, int l, int k) {
    if (t == NULL) return;
    if (l == k) 
        enqueue(q, t);

    nodiAltezza(figlioSX(t), q, l - 1 , k);
    nodiAltezza(figlioDX(t), q, l - 1, k);
}

int contaNodi(BST t) {
    if (t == NULL) return 0;

    return 1 + contaNodi(figlioSX(t)) + contaNodi(figlioDX(t));
}

int isMediano(BST t, Item it) {
    // if (t == NULL) return 0;
    if (!contains(t, it)) return 0;

    if (isEqual(getItem(t), it)) {
        return contaNodi(figlioSX(t)) == contaNodi(figlioDX(t));
    }

    return isMediano(figlioSX(t), it) || isMediano(figlioDX(t), it);
}