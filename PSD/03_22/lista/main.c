#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    Node head = NULL;

    addFront(&head, 1);
    addEnd(&head, 10);
    addEnd(&head, 20);
    addEnd(&head, 30);
    addEnd(&head, 40);
    addFront(&head, 50);
    printList(head);

    int n = countNodes(head);

    printf("\n%d", n);

    return 0;
}
