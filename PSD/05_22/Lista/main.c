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

    removePos(l, 4);
    printf("\n\nList after removing the element at position 4:\n\n");
    printList(l);

    removeFirst(l);
    printf("\nList after removing the first element:\n\n");
    printList(l);

    removeLast(l);
    printf("\nList after removing the last element:\n\n");
    printList(l);

    freeList(l);

    return 0;
}
