#include "btree.h"

typedef struct Queue *Queue;

Queue newQueue(void);

int isEmptyQueue(Queue q);

int enqueue(Queue q, Btree t);

Btree dequeue(Queue q);

void freeQueue(Queue q);
