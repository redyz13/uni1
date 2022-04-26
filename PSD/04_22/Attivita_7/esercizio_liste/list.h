#include "item.h"

typedef struct List *List;

// Create a new list
List newList(void);

// Check if the list is empty
int isEmpty(List list);

/* Add a value into the first position of the list
*  in case of error return 0
*/
int addFirst(List list, Item it);

/* Add a value into the last position of the list
*  if there are no values, add it as the first
*  in case of error return 0
*/
int addLast(List list, Item it);

/* Add a value to the given position, if the position
*  doesn't exist return 0, if the position is the last,
*  add the value to the end, if the position is 0, add the
*  value at the beginning
*/
int add(List list, Item it, int pos);

/* Remove the first occurence of the given data,
*  if the list is empty or the data to delete
*  isn't found return 0
*/
int removeItem(List list, Item it);

/* Remove the first value in the list
*  if the list is empty return 0
*/
int removeFirst(List list);

/* Remove the last value in the list
*  if the list is empty return 0
*/
int removeLast(List list);

/* Remove a value to the given position, if the position
*  doesn't exist return 0, if the position is 0, remove the
*  value at the beginning
*/
int removeItemPos(List list, int pos);

/* Set the given value to the given position
*  if the position is 0, set the value at the beginning
*  if the list is empty or the position isn't found 
*  return 0
*/
int set(List list, Item it, int pos);

/* Get the value at the given position, if the position
*  doesn't exist return NULLITEM, if the position is 0, get the 
*  value at the beginning
*/
Item get(List list, int pos);

/* Get the first value, if the list is empty, return
*  NULLITEM
*/
Item getFirst(List list);

/* Get the last value, if the list is empty, return
*  NULLITEM
*/
Item getLast(List list);

// Check if the value is in the list
int contains(List list, Item it);

/* Return the position of the value in the list
*  if the value isn't found return -1
*/
int indexOf(List list, Item it);

/* Return a cloned list of the given one
*  if the given list is empty return null
*/ 
List clone(List list);

// Print the entire list to stdout
void printList(List list);

/* Return a reversed list of the given list
*  and free the old list
*/
List reverseList(List list);

// Free the entire list
void freeList(List list);

// Free the entire list and its data (XXX)
void destroyList(List list);

// Switch a coppie della lista
int switchCoppie(List list);

// Elimina il valore al centro
int eliminaCentro(List list);
