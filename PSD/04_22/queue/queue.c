#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Node {
    Item data;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
    int size;
};

Queue newQueue(void) {
    Queue q;

    q = malloc(sizeof(struct Queue));

    if(q == NULL) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

int isEmpty(Queue q) {
    return q->size == 0;
}

int enqueue(Queue q, Item it) {
    struct Node *n;

    n = malloc(sizeof(struct Node));

    if(n == NULL) return 0;

    n->data = it;
    n->next = NULL;

    if(q->head == NULL) {
        q->head = n;
        q->tail = n;
        (q->size)++;
        return 1;
    }

    q->tail->next = n;
    q->tail = n;

    (q->size)++;

    return 1;
}

Item dequeue(Queue q) {
    if(isEmpty(q)) return 0;

    Item val;
    struct Node *tmp;

    val = q->head->data;

    tmp = q->head;
    q->head = q->head->next;
    free(tmp);

    if(q->head == NULL) {
        q->tail = NULL;
    }

    (q->size)--;

    return val;
}

void freeQueue(Queue q) {
    struct Node *head, *tmp;

    head = q->head;

    while(head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    free(q);
}
