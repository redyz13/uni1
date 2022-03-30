#include "item.h"

typedef struct Node *Node;

// Create a new node
Node newNode(item x);

// Return data of a node
item getData(Node n);

// Print the entire list
void printList(Node head);

/* Add a node to the end, if there are
*  no nodes, set the created one as head 
*/
void addEnd(Node *head, item x);

/* Add a node to the front, if there are
*  no nodes, set the created one as head 
*/
void addFront(Node *head, item x);

/* Add the node at the given position
*  in the list, if the pos is the last, just
*  add the node to the end, if the pos is 0, set the
*  created one as head
*/
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
void removePos(Node *head, int pos);

// Reverse the entire list
void reverseList(Node *head);
