#include <stdio.h>
#include "list.h"

int main(void) {
    List l;

    l = newList();

    addFront(l, 10);
    addFront(l, 20);
    addFront(l, 30);
    addFront(l, 40);
    addFront(l, 50);
    addLast(l, 100);
    addPos(l, 999, 4);

    // l = reverseList(l);
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

    removeItem(l, 30);
    printf("\nList after removing the element 30:\n\n");
    printList(l);

    printf("\nCloned list:\n\n");
    List k = cloneList(l);
    printList(k);

    freeList(l);
    freeList(k);

    return 0;
}
