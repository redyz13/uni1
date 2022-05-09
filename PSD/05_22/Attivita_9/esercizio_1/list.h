#include "item.h"

typedef struct Node *List;

List newList(void);

int isEmpty(List head);

int addFirst(List *head, Item it);

int sizeList(List head);

int sizeListRec(List head);

void printList(List head);