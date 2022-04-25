#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue q;

    q = newQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    int x = dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q, 40);

    int y = dequeue(q);

    dequeue(q);
    dequeue(q);
    enqueue(q, 50);

    int z = dequeue(q);

    printf("%d", x);
    printf("\n%d", y);
    printf("\n%d", z);

    freeQueue(q);

    return 0;
}
