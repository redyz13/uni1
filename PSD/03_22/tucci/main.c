#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List l;

    l = newList();

    addFront(l, 10);

    printList(l);
    freeList(l);

    return 0;
}
