#include <limits.h>

// Give the item a type (TODO)
typedef int Key;

#define NULLITEM 0
#define ITEM_MAX INT_MAX
#define ITEM_MIN INT_MIN

// Print data of an item to stdout
void printItem(Key it);

// Deallocate an item (to use only if the item is allocated) 
void freeItem(Key it);

// Return 1 if the items are equal 0 if not
int isEqual(Key it1, Key it2);

int isMinus(Key it1, Key it2);
