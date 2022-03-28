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
    removeNodePos(&head, 0);
    removeNodePos(&head, 0);
    removeNodePos(&head, 5);
    removeNodePos(&head, 5);
    addPos(&head, 22, 0);
    addPos(&head, 122, 6);
    printList(head);
    freeList(head);

    return 0;
}
