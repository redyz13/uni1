#include "pqueue.h"

PQueue creaPQueue(void);

Key maxPQueue(PQueue q);

Key minPQueue(PQueue q);

void incrementaChiave(PQueue q, Key k, Key newK);

void stampaArray(int *arr, int size);

void heapify(int *arr, int size);
