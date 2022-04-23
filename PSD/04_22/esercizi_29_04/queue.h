#include "punto.h"

typedef struct Queue *Queue;

Queue newQueue(void);

int isEmpty(Queue q);

int enqueue(Queue q, Punto p);

Punto dequeue(Queue q);

void freeQueue(Queue q);

void destroyQueue(Queue q);
