#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    Node head = NULL;

    for(int i = 0; i < 10; i++) {
        addFront(&head, i);
    }

    removeNode(&head, 5);
    removeNode(&head, 88);
    reverseList(&head);
    removePos(&head, 0);
    removePos(&head, 0);
    removePos(&head, 5);
    removePos(&head, 5);
    addPos(&head, 22, 0);
    addPos(&head, 42, 0);
    addPos(&head, 62, 1);
    addPos(&head, 88, 2);
    addPos(&head, 188, 9);
    addPos(&head, 288, 9);
    addPos(&head, 688, 10);
    printList(head);
    freeList(head);

    return 0;
}
