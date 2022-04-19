#include "item.h"

typedef struct Node *Node;

// Create a new node
Node newNode(Item it);

// Check if the node is null
int isNull(Node node);

// Return data of a node
Item getItem(Node node);

// Given a node return the next node
Node nextNode(Node node);

/* Add a node to the front, if there are
*  no nodes, set the created one as head 
*  return the new head
*/
Node addHead(Node head, Item it);

/* Add a node to the front, if there are
*  no nodes, set the created one as head 
*  return the new head
*/
Node addTail(Node head, Item it);

/* Add a node to the given position, if the position
*  doesn't exist return null, if the position is the last,
*  add the node to the end, if the position is 0, set the
*  created one as head
*/
Node addPos(Node head, Item it, int pos);

/* Remove the first occurence of the node that has the
*  given data, if there are no nodes return null
*/
Node removeNode(Node head, Item it);

/* Remove a node to the given position, if the position
*  doesn't exist return null, if the position is 0, remove the
*  head
*/
Node removePos(Node head, int pos);

/* Set the given value in the node to the given position
*  if the position is 0, set the value of the head
*  if there are no nodes return null
*/
Node setNode(Node head, Item it, int pos);

/* Get the value at the given position, if the position
*  doesn't exist return NULLITEM, if the position is 0, get the 
*  value of the head
*/
Item getItemPos(Node head, int pos);

// Return the number of nodes
int countNodes(Node head);
