#include <limits.h>

// Give the item a type (TODO)
typedef int Item;

#define NULLITEM 0
#define ITEM_MAX INT_MAX 
#define ITEM_MIN INT_MIN 

// Print data of an item to stdout
void printItem(Item it);

// Deallocate an item (to use only if the item is allocated) 
void freeItem(Item it);

// Return 1 if the items are equal 0 if not
int isEqual(Item it1, Item it2);
