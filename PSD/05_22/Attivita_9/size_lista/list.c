#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node {
    struct Node *next;
    Item data;
};

List newList(void) {
    return NULL;
}

int isEmpty(List head) {
    return head == NULL;
}

int addFirst(List *head, Item it) {
    struct Node *new;

    new = malloc(sizeof(struct Node));
    if (new == NULL) return 0;

    new->data = it;

    if (*head == NULL) {
        new->next = NULL;
        *head = new;
        return 1;
    }

    new->next = *head;
    *head = new;

    return 1;
}

int sizeList(List head) {
    if (head == NULL) return 0;

    int i = 0;

    while (head != NULL) {
        i++;
        head = head->next;
    }

    return i;
}

int sizeListRec(List head) {
    if (head == NULL) return 0;

    return 1 + sizeListRec(head->next);
}

void printList(List head) {
    int i = 0;

    while (head != NULL) {
        printf("--- Element %d ---\n", i++);
        printItem(head->data);
        putchar('\n');
        head = head->next;
    }
}
