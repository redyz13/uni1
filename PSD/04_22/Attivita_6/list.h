#include "punto.h"

typedef struct Node* List;

List newList();

int isEmpty(List l);

List tailList(List l);

List addHead(List l, Punto p);

Punto getFirst(List l);

void printList(List l);

int sizeList(List l);

int posItem(List l, Punto p);

//int searchItem(List l, Punto p);

List reverseList(List l);

//List removeItem(List l, Punto p);

Punto getItem(List l, int pos);

//List insertList(List l, Punto p, int pos);

List removeList(List l, int pos);
