#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    Node head = NULL;

    addFront(&head, 1);
    addEnd(&head, 10);
    addEnd(&head, 20);
    addFront(&head, 20);

    freeList(head);

    return 0;
}
