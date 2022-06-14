#include "item.h"

typedef struct List *List;

List newList(void);

int isEmptyList(List l);

int addFirst(List l, Item it);

int addLast(List l, Item it);

int addPos(List l, Item it, int pos);

Item getFirst(List l);

Item getLast(List l);

Item getPos(List l, int pos);

int removeFirst(List l);

int removeLast(List l);

int removePos(List l, int pos);

int removeItem(List l, Item it);

int contains(List l, Item it);

int indexOf(List l, Item it);

int setValue(List l, Item it, int pos);

void printList(List l);

List reverseList(List l);

List cloneList(List l);

void freeList(List l);

void destroyList(List l);
