#include "btree.h"
#include "queue.h"

typedef struct Diff Diff;

Btree createBtree(void);

int contaFoglie(Btree t);

Btree speculare(Btree t);

Item max(Btree t);

Item min(Btree t);

int uguali(Btree t1, Btree t2);

int uguali_diff(Btree t1, Btree t2, Diff *diff);

Btree aggiungiNodo(Btree t, Item nodo);
