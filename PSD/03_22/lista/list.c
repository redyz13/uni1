#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

struct Node {
    item data;
    struct Node *next;
};

Node newNode(item x) {
    Node node;

    node = malloc(sizeof(struct Node));

    if(node == NULL) return NULL;

    node->data= x;
    node->next = NULL;

    return node;
}

int getValue(Node n) {
    return n->data;
}

void printList(Node head) {
    int i = 0;

    while(head != NULL) {
        printf("Element %d = ", i++);
        printItem(head->data);
        putchar('\n');
        head = head->next;
    }
}

int countNodes(Node head) {
    int i = 1;

    if(head == NULL) {
        return i;
    }

    while(head->next != NULL) {
        head = head->next;
        i++;
    }

    return i;
}

void addEnd(Node *head, item x) {
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

void addFront(Node *head, item x) {
    Node new;

    new = newNode(x);

    if(*head == NULL) {
        *head = new;
        return;
    }

    if(new != NULL) {
        new->next = *head;
        *head = new;
    }
}
