#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node {
    Item data;
    struct Node *next;
};

struct Stack {
    struct Node *head;
    int size;
};

Stack newStack(void) {
    Stack s;

    s = malloc(sizeof(struct Stack));

    if(s == NULL) return NULL;

    s->head = NULL;
    s->size = 0;

    return s;
}

int isEmpty(Stack s) {
    return s->size == 0;
}

int push(Stack s, Item it) {
    struct Node *n;

    n = malloc(sizeof(struct Node));

    if(n == NULL) return 0;

    n->data = it;
    n->next = s->head;

    s->head = n;

    (s->size)++;

    return 1;
}

int pop(Stack s) {
    if(isEmpty(s)) return 0;

    struct Node *tmp;

    tmp = s->head;

    s->head = s->head->next;

    free(tmp);

    (s->size)--;

    return 1;
}

Item top(Stack s) {
    if(isEmpty(s)) return NULLITEM;

    return s->head->data;
}

void freeStack(Stack s) {
    struct Node *head, *tmp;

    head = s->head;

    while(head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    free(s);
}
