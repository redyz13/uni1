#include "item.h"

typedef struct Node *Node;

Node newNode(item x);
int getValue(Node n);
void printList(Node head);
void addEnd(Node *head, item x);
void addFront(Node *head, item x);
int countNodes(Node head);
void freeList(Node head);
