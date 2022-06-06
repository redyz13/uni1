#include "item.h"

typedef struct Node *Btree;

Btree newBtree(void);

int isEmptyBtree(Btree t);

Item getItemBtree(Btree t);

void setItemBtree(Btree t, Item it);

Btree figlioSX(Btree t);

Btree figlioDX(Btree t);

struct Node *getRoot(Btree t);

Btree consBtree(Item it, Btree sx, Btree dx);

void preorder(Btree T);

void print2DBtree(Btree root);
