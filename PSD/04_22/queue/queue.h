#include "item.h"

typedef struct Queue *Queue;

Queue newQueue(void);

int isEmpty(Queue q);

int enqueue(Queue q, Item it);

Item dequeue(Queue q);

void freeQueue(Queue q);
