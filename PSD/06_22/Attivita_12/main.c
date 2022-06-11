#include <stdio.h>
#include "util.h"

int main(void) {
    PQueue q;

    q = creaPQueue();

    printf("Coda: ");
    printPQueue(q);

    putchar('\n');

    return 0;
}

PQueue creaPQueue(void) {
    PQueue q = newPQ();

    insert(q, 15);
    insert(q, 12);
    insert(q, 14);
    insert(q, 10);
    insert(q, 7);
    insert(q, 6);
    insert(q, 9);
    insert(q, 2);
    insert(q, 5);
    insert(q, 3);

    return q;
}
