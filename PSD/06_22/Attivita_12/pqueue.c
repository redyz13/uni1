#include <stdlib.h>
#include "pqueue.h"

#define MAXPQ 50

struct PQueue {
    int vet[MAXPQ];
    int size;
};

static void scendi(PQueue q) {
    int tmp, pos, i = 1, size = q->size;

    while (1) {
        if (i * 2 + 1 <= size) {
            pos = (q->vet[i * 2] > q->vet[i * 2 + 1]) ? i * 2 : i * 2 + 1;
        }
        else if (i * 2 <= size) {
            pos = i * 2;
        }
        else break;

        if (q->vet[pos] > q->vet[i]) {
            tmp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = tmp;

            i = pos;
        }
        else break;
    }
}

static void sali(PQueue q) {
    int tmp, pos = q->size, i = pos / 2;

    while (pos > 1) {
        if (q->vet[pos] > q->vet[i]) {
            tmp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = tmp;

            pos = i;
            i = pos / 2;
        }
        else break;
    }
}

PQueue newPQ(void) {
    PQueue q;

    q = malloc(sizeof(struct PQueue));
    if (q == NULL) return NULL;

    q->size = 0;
    return q;
}

int isEmpty(PQueue q) {
    if (q == NULL) return 1;

    return q->size == 0;
}

Key getMax(PQueue q) {
    return q->vet[1];
}

int deleteMax(PQueue q) {
    if (q == NULL || q->size == 0) return 0;

    q->vet[1] = q->vet[q->size];

    (q->size)--;

    scendi(q);

    return 1;
}

int insert(PQueue q, Key k) {
    if (q == NULL || q->size == 0) return 0;

    (q->size)++;

    q->vet[q->size] = k;

    sali(q);

    return 1;
}
