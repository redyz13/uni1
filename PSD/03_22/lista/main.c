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
    printList(head);
    freeList(head);

    return 0;
}
