#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "util.h"

int main(void) {
    PQueue q;

    q = creaPQueue();

    printf("Coda: ");
    printPQueue(q);

    printf("\n\nMassimo: %d", maxPQueue(q));
    printf("\nMinimo: %d", minPQueue(q));

    printf("\n\nCoda dopo min: ");
    printPQueue(q);

    incrementaChiave(q, 6, 13);

    printf("\nCoda dopo incrementa chiave: ");
    printPQueue(q);

    int arr[] = { 5, 7, 9, 3, 11, 29, 4 };

    printf("\n\nArray non ordinato: ");
    stampaArray(arr, 7);

    heapify(arr, 7);

    printf("\nArray dopo heapify: ");
    stampaArray(arr, 7);

    PQueue a = newPQ();
    insert(a, 17); insert(a, 1); insert(a, 10);

    printf("\n\nCoda 1: ");
    printPQueue(q);
    printf("\nCoda 2: ");
    printPQueue(a);

    PQueue mer = merge(q, a);
    printf("\nCoda data dal merge: ");
    printPQueue(mer);

    printf("\nStampa stringa: ");
    cosaNarducci("P R I O * R * * I * T * Y * * * Q U E * * * U * E");

    putchar('\n');

    return 0;
}

PQueue creaPQueue(void) {
    PQueue q = newPQ();

    insert(q, 15);
    insert(q, 12);
    insert(q, 10);
    insert(q, 7);
    insert(q, 6);
    insert(q, 9);
    insert(q, 2);
    insert(q, 3);

    return q;
}

Key maxPQueue(PQueue q) {
    return getMax(q);
}

Key minPQueue(PQueue q) {
    PQueue tmp = newPQ();
    int min, k;

    min = getMax(q);
    deleteMax(q);
    insert(tmp, min);

    while (!isEmpty(q)) {
        k = getMax(q);
        insert(tmp, k);

        if (min > k) {
            min = k;
        }

        deleteMax(q);
    }

    while (!isEmpty(tmp)) {
        k = getMax(tmp);
        insert(q, k);
        deleteMax(tmp);
    }

    free(tmp);

    return min;
}

void incrementaChiave(PQueue q, Key k, Key newK) {
    if (k >= newK) return;

    PQueue tmp = newPQ();
    int key;

    while (!isEmpty(q)) {
        key = getMax(q);
        insert(tmp, key);
        deleteMax(q);
    }

    while (!isEmpty(tmp)) {
        key = getMax(tmp);

        if (key == k) {
            insert(q, newK);
        }
        else {
            insert(q, key);
        }

        deleteMax(tmp);
    }

    free(tmp);
}

void stampaArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void heapify(int *arr, int size) {
    int i, j, tmp;

    for (i = 0; i < size - 1; i++)  {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int push(PQueue q, Key k) {
    if (k < getMax(q)) return 0;

    insert(q, k);

    return 1;
}

int pop(PQueue q) {
    deleteMax(q);

    return 1;
}

PQueue merge(PQueue q1, PQueue q2) {
    if (isEmpty(q1) || isEmpty(q2)) return NULL;

    PQueue new = newPQ();
    PQueue tmp = newPQ();
    Key k;

    while (!isEmpty(q1)) {
        k = getMax(q1);
        insert(tmp, k);
        insert(new, k);
        deleteMax(q1);
    }

    while (!isEmpty(tmp)) {
        k = getMax(tmp);
        insert(q1, k);
        deleteMax(tmp);
    }

    while (!isEmpty(q2)) {
        k = getMax(q2);
        insert(tmp, k);
        insert(new, k);
        deleteMax(q2);
    }

    while (!isEmpty(tmp)) {
        k = getMax(tmp);
        insert(q2, k);
        deleteMax(tmp);
    }

    free(tmp);

    return new;
}

void cosaNarducci(char *s) {
    PQueue q = newPQ();

    while (*s) {
        if (isalpha(*s)) {
            insert(q, *s);
        }
        else if (*s == '*') {
            printKeyAsChar(getMax(q));
            putchar(' ');
            deleteMax(q);
        }
        s++;
    }
}
