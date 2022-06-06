#include "item.h"

typedef struct Node *BST;

BST newBST(void);

int isEmpty(BST t);

Item getItem(BST t);

BST figlioSX(BST t);

BST figlioDX(BST t);

BST insertNode(BST t, Item it);

int contains(BST t, Item it);

BST deleteNode(BST t, Item it);

void print2D(BST root);
