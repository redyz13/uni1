#include <stdio.h>
#include "list.h"

int main(void) {
    List l;

    l = newList();

    addFront(l, 10);
    addFront(l, 20);
    addFront(l, 30);
    addLast(l, 100);
    addPos(l, 999, 4);

    printList(l);

    printf("\nFirst element: %d", getFirst(l));
    printf("\nLast element: %d", getLast(l));
    printf("\nElement at position 3: %d", getPos(l, 3));

    removePos(l, 1);
    printf("\n\nList after removing the element at position 1:\n");
    printList(l);

    return 0;
}