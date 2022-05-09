#include <stdio.h>
#include "list.h"

int main(void) {
    List l;

    l = newList();

    addFirst(&l, 10);
    addFirst(&l, 20);
    addFirst(&l, 30);
    addFirst(&l, 40);
    addFirst(&l, 50);
    addFirst(&l, 100);

    printList(l);

    printf("\nCount: %d", sizeListRec(l));

    return 0;
}