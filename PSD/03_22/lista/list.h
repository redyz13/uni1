#include "item.h"

typedef struct Node *Node;

// Create a new node
Node newNode(item x);

// Return data of a node
item getData(Node n);

// Print the entire list
void printList(Node head);

// Add a node to the end
void addEnd(Node *head, item x);

// Add a node to the front
void addFront(Node *head, item x);

void addPos(Node *head, item x, int pos);

// Get the number of nodes
int countNodes(Node head);

// Free the entire list
void freeList(Node head);

/* Remove the first occurence of the node that has the
*  passed data
*/
void removeNode(Node *head, item x);

/* Remove the the node that has the
*  given position in the list
*/
void removeNodePos(Node *head, int pos);

// Reverse the entire list
void reverseList(Node *head);
