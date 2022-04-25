#include "processo.h"

typedef struct Queue *Queue;

Queue newQueue(void);

int isEmpty(Queue q);

int enqueue(Queue q, Processo p);

Processo dequeue(Queue q);

void printQueue(Queue q);

void freeQueue(Queue q);

void destroyQueue(Queue q);
