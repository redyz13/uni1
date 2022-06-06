#include "item.h"

typedef struct Node *Btree;

Btree newBtree(void);

int isEmpty(Btree t);

Item getItem(Btree t);

void setItem(Btree t, Item it);

Btree figlioSX(Btree t);

Btree figlioDX(Btree t);

struct Node *getRoot(Btree t);

Btree consBtree(Item it, Btree sx, Btree dx);

void preorder(Btree T);

void print2D(Btree root);
