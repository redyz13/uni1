#include "item.h"

typedef struct List *List;

List newList(void);

int isEmpty(List l);

int addFront(List l, Item it);

int addLast(List l, Item it);

int addPos(List l, Item it, int pos);

Item getFirst(List l);

Item getLast(List l);

Item getPos(List l, int pos);

int removeFirst(List l);

int removeLast(List l);

int removePos(List l, int pos);

void printList(List l);

void freeList(List l);
