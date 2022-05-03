#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

struct Node {
    Canzone c;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
    int size;
};

Playlist newPlaylist(void) {
    Playlist p;

    p = malloc(sizeof(struct Queue));
    if(p == NULL) return NULL;

    p->head = NULL;
    p->tail = NULL;
    p->size = 0;

    return p;
}

int isEmpty(Playlist p) {
    return p->size == 0;
}

void printPlaylist(Playlist p) {
    struct Node *head;
    int i = 0;

    head = p->head;

    printf("\n[Playlist attuale]\n\n");

    while(head != NULL) {
        printf("--- Canzone %d ---\n", i++);
        printCanzone(head->c);
        putchar('\n');
        head = head->next;
    }
}

int enqueue(Playlist p, Canzone c) {
    struct Node *new;

    new = malloc(sizeof(struct Node));
    if(new == NULL) return 0;

    new->c = c;
    new->next = NULL;

    if(isEmpty(p)) {
        p->head = new;
        p->tail = new;
        (p->size)++;
        return 1;
    }

    p->tail->next = new;
    p->tail = new;
    (p->size)++;

    return 1;
}

Canzone dequeue(Playlist p) {
    if(isEmpty(p)) return NULLITEM;

    struct Node *tmp;
    Canzone ca;

    ca = p->head->c;

    tmp = p->head;
    p->head = p->head->next;
    free(tmp);
    (p->size)--;

    return ca;
}

int removeCanzone(Playlist p, int pos) {
    if(isEmpty(p)) return 0;

    struct Node *head = p->head;
    struct Node *tmp;

    if(pos == 0) {
        tmp = p->head;
        p->head = p->head->next;
        free(tmp);
        return 1;
    }

    int i = 0;

    while(i < pos - 1 && head != NULL) {
        head = head->next;
        i++;
    }

    if(head == NULL) return 0;
    if(head->next == NULL) return 0;

    tmp = head->next;
    head->next = tmp->next;
    free(tmp);

    return 1;
}

int forward(Playlist p, int pos) {
    if(isEmpty(p)) return 0;

    struct Node *head = p->head;
    Canzone to_forward;
    int i = 0;

    while(i < pos && head != NULL) {
        head = head->next;
        i++;
    }

    if(head == NULL) return 0;
    if(head->next == NULL) return 0;

    to_forward = head->c;
    head->c = head->next->c;
    head->next->c = to_forward;

    return 1;
}

int back(Playlist p, int pos) {
    if(isEmpty(p)) return 0;

    struct Node *head = p->head;
    Canzone to_forward;
    int i = 0;

    if(pos == 0) return 0;

    while(i < pos - 1 && head != NULL) {
        head = head->next;
        i++;
    }

    if(head == NULL) return 0;
    if(head->next == NULL) return 0;

    to_forward = head->c;
    head->c = head->next->c;
    head->next->c = to_forward;

    return 1;
}

Playlist canzoniCantante(Playlist p, char *cantante) {
    if(isEmpty(p)) return NULL;

    Playlist s;
    struct Node *head = p->head;
    char *cantante_tmp;

    s = newPlaylist();

    while(head != NULL) {
        cantante_tmp = getCantante(head->c);

        if(!(strcmp(cantante, cantante_tmp))) {
            enqueue(s, head->c);
        }

        head = head->next;
    }

    return s;
}

void freePlaylist(Playlist p) {
    struct Node *tmp;

    while(p->head != NULL) {
        tmp = p->head;
        p->head = p->head->next;
        free(tmp);
    }

    free(p);
}
