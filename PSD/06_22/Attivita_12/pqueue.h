#include "key.h"

typedef struct PQueue *PQueue;

PQueue newPQ(void);

int isEmpty(PQueue q);

Key getMax(PQueue q);

int deleteMax(PQueue q);

int insert(PQueue q, Key k);
