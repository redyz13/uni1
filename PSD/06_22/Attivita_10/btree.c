#include <stdlib.h>
#include "btree.h"

struct Node {
    Item data;
    struct Node *left;
    struct Node *right;
};

static void setItem(Btree t, Item it) {
    if (t == NULL) return;

    t->data = it;
}

static Item getItem(Btree t) {
    if (t == NULL) return NULLITEM;

    return t->data;
}

Btree newBtree(void) {
    return NULL;
}

int isEmpty(Btree t) {
    return t == NULL;
}

Btree figlioSX(Btree t) {
    if (t == NULL) return NULL;

    return t->left;
}

Btree figlioDX(Btree t) {
    if (t == NULL) return NULL;

    return t->right;
}

Btree consBtree(Item it, Btree sx, Btree dx) {
    Btree new;

    new = malloc(sizeof(struct Node));
    if (new == NULL) return NULL;

    setItem(new, it);

    new->left = sx;
    new->right = dx;

    return new;
}
