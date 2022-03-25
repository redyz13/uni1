#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node {
    int value;
    struct Node *next;
};

Node newNode(int x) {
    Node node;

    node = malloc(sizeof(struct Node));

    if(node == NULL) return NULL;

    node->value = x;
    node->next = NULL;

    return node;
}

int getValue(Node n) {
    return n->value;
}

void printList(Node head) {
    int i = 0;

    while(head != NULL) {
        printf("Element %d = %d\n", i++, head->value);
        head = head->next;
    }
}

void addEnd(Node *head, int x) {
    Node new, last;

    new = newNode(x);

    last = *head;

    if(new != NULL) {
        if(*head == NULL) {
            *head = new;
            return;
        }

        while(last->next != NULL) {
            last = last->next;
        }

        last->next = new;
    }
}

void addFront(Node *head, int x) {
    Node new;

    new = newNode(x);

    if(new != NULL) {
        new->next = *head;
        *head = new;
    }
}
