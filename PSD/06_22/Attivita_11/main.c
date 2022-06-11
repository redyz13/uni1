#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(void) {
    BST bst = creaBST();

    printf("Albero binario di ricerca:\n");

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
    printf("\nMediano: %d\n", isMediano(bst, 5));

    printf("Gli archi tra %d e %d sono: %d\n", 5, 3, conta_archi(bst, 5, 3));
    
    printf("L'antenato comune tra %d e %d è: ", 35, 25);
    printItem(antenatoComune(bst, 35, 25));

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
    if (t == NULL) return 0;

    if (contains(t, it)) {
        if (figlioSX(t) == NULL && figlioDX(t) == NULL) return 1;
        if (isEqual(it, getItem(t))) {
            return (contaNodi(figlioSX(t)) == contaNodi(figlioDX(t)));
        }
        else {
            return isMediano(figlioSX(t), it) || isMediano(figlioDX(t), it);
        }
    }

    return 0;
}

int conta_elementi(Queue q) {
    Queue tmp = newQueue();
    BST node; 
    int count = 0;

    while (!isEmptyQueue(q)) {
        node = dequeue(q);
        count++;
        enqueue(tmp, node);
    }

    while (!isEmptyQueue(tmp)) {
        node = dequeue(tmp);
        enqueue(q, node);
    }

    return count;
}

int archi(Queue q1, Queue q2) {
    BST node1, node2;
    int count = 0, count1, count2, num_archi;

    count1 = conta_elementi(q1);
    count2 = conta_elementi(q2);
    
    enqueue(q2, NULL);

    while (!isEmptyQueue(q1)) {
        node1 = dequeue(q1);

        while (1) {
            node2 = dequeue(q2);

            if (node2 == NULL) {
                break;
            }

            if (isEqual(getItem(node1), getItem(node2))) {
                count++;
            }

            enqueue(q2, node2);
        }

        enqueue(q2, NULL);
    }

    num_archi = (count1 + count2) - (2 * count);

    return num_archi;
}

void conta(BST t, Item it, Queue q) {
    if (t == NULL) return;
    
    if (!(isEqual(getItem(t), it))) {
        if (contains(figlioDX(t), it)) {
            conta(figlioDX(t), it, q);
            enqueue(q, t);
        }
        else if (contains(figlioSX(t), it)) {
            conta(figlioSX(t), it, q);
            enqueue(q, t);
        }
    }
    else {
        enqueue(q, t);
        return;
    }

    return;
}

int conta_archi(BST t, Item it1, Item it2) {
    Queue cu = newQueue();
    Queue cucu = newQueue();
    conta(t, it1, cu);
    conta(t, it2, cucu);
    
    return archi(cu, cucu);
}

Item antenatoComune(BST t, Item it1, Item it2) {
    if (t == NULL) return NULLITEM;

    if (it1 == it2) return it1;

    if (contains(figlioSX(t), it1) && contains(figlioSX(t), it2)) {
        antenatoComune(figlioSX(t), it1, it2);
    }
    else if (contains(figlioDX(t), it1) && contains(figlioDX(t), it2)) {
        antenatoComune(figlioDX(t), it1, it2);
    }
    else {
        return getItem(t); 
    }
}
