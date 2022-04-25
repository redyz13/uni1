#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"

int main(void) {
    Queue q;
    int burst;

    q = newQueue();

    codaProcessi(q, 5);

    printQueue(q);

    printf("Inserire il numero di cicli di clock: ");
    scanf("%d", &burst);

    schedule(q, burst);

    printf("\nTerminazione\n");

    freeQueue(q);
}

void codaProcessi(Queue q, size_t n) {
    Processo p;
    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        p = creaProcesso(i, rand() % 100);
        enqueue(q, p);
    }
}

void schedule(Queue q, int burst) {
    Processo p;
    int cpu_b, diff, i = 0;

    while(!isEmpty(q)) {
        p = dequeue(q);
        cpu_b = getBurst(p);

        diff = cpu_b - burst;

        if(diff <= 0) {
            freeProcesso(p);
        }
        else {
            setBurst(p, diff);
            enqueue(q, p);
        }

        printf("\n--- Ciclo di clock %d ---\n\n", i++);
        printQueue(q);
        printf("-------------------------\n");
    }
}
