#include "bst.h"
#include "btree.h"
#include "queue.h"

#define NODES 10

#define A consBtree(3, NULL, NULL)
#define B consBtree(4, NULL, NULL)
#define C consBtree(5, B, A)
#define D consBtree(15, NULL, NULL)
#define E consBtree(10, C, D)
#define F consBtree(35, NULL, NULL)
#define G consBtree(40, F, NULL)
#define H consBtree(25, NULL, NULL)
#define I consBtree(30, H, G)
#define T consBtree(20, E, I)

BST creaBST(void);

int isBST(Btree t);

void inserisciArray(BST t, Item *arr, int size);

void nodiIntervallo(BST t, Item a, Item b);

void nodi_intervallo(BST t, Item a, Item b);

Queue stampaLivello(BST t, Queue q, int k);

BST arrToBST(BST t, int *arr, int size, int i);

int getLivello(BST t);

void nodiAltezza(BST t, Queue q, int l, int k);

int contaNodi(BST t);

int isMediano(BST t, Item it);