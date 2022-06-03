#include "item.h"

typedef struct Node *Btree;

Btree newBtree(void);

int isEmpty(Btree t);

Btree figlioSX(Btree t);

Btree figlioDX(Btree t);

Btree consBtree(Item it, Btree sx, Btree dx);
