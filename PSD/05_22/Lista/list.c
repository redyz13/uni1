#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node {
    struct Node *next;
    Item data;
};

struct List {
    struct Node *head;
    int size;
};

List newList(void) {
    List l;

    l = malloc(sizeof(struct List));
    if (l == NULL) return l;

    l->head = NULL;
    l->size = 0;

    return l;
}

int isEmpty(List l) {
    return l->size == 0;
}

int addFront(List l, Item it) {
    struct Node *new;

    new = malloc(sizeof(struct Node));
    if (new == NULL) return 0;

    new->data = it;

    if (l->head == NULL) {
        new->next = NULL;
        l->head = new;
        (l->size)++;
        return 1;
    }

    new->next = l->head;
    l->head = new;
    (l->size)++;

    return 1;
}

int addLast(List l, Item it) {
    struct Node *new;

    new = malloc(sizeof(struct Node));
    if (new == NULL) return 0;

    new->data = it;
    new->next = NULL;

    if (l->head == NULL) {
        l->head = new;
        (l->size)++;
        return 1;
    }

    struct Node *last = l->head;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new;
    (l->size)++;

    return 1;
}

int addPos(List l, Item it, int pos) {
    struct Node *new;

    new = malloc(sizeof(struct Node));
    if (new == NULL) return 0;

    new->data = it;

    if (pos == 0) {
        new->next = l->head;
        l->head = new;
        (l->size)++;
        return 1;
    }

    int i = 0;
    struct Node *tmp = l->head;

    while (i < pos - 1 && tmp != NULL) {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL) {
        free(new);
        return 0;
    }

    new->next = tmp->next;
    tmp->next = new;

    (l->size)++;

    return 1;
}

Item getFirst(List l) {
    if (l->head == NULL) return NULLITEM;

    return l->head->data;
}

Item getLast(List l) {
    return getPos(l, (l->size) - 1);
}

Item getPos(List l, int pos) {
    if (l->head == NULL) return NULLITEM;

    if (pos == 0) return l->head->data;

    int i = 0;
    struct Node *tmp = l->head;

    while (i < pos && tmp != NULL) {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL) return NULLITEM;

    return tmp->data;
}

int removeFirst(List l) {
    if (l->head == NULL) return 0;

    struct Node *tmp = l->head;

    l->head = l->head->next;
    free(tmp);
    (l->size)--;

    return 1;
}

int removeLast(List l);

int removePos(List l, int pos) {
    if (l->head == NULL) return 0;

    struct Node *tmp = l->head;

    if (pos == 0) {
        l->head = l->head->next;
        free(tmp);
        (l->size)--;
        return 1;
    }

    int i = 0;
    struct Node *prev = l->head;

    while (i < pos - 1 && prev != NULL) {
        prev = prev->next;
        i++;
    }

    if (prev == NULL)  return 0;
    if (prev->next == NULL)  return 0;

    tmp = prev->next;
    prev = tmp->next;
    free(tmp);
    (l->size)--;

    return 1;
}

void printList(List l) {
    struct Node *head = l->head;
    int i = 0;

    while (head != NULL) {
        printf("--- Element %d ---\n", i++);
        printItem(head->data);
        putchar('\n');
        head = head->next;
    }
}