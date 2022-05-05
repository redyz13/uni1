#include <stdio.h>
#include "item.h"

// Change the function based on the item type (TODO in case)
void printItem(Item it){
    printf("%d", it);
}

/* Change the function based on the item type (TODO in case)
*  You will need this function only if the item is allocated
*/
void freeItem(Item it) {
    ;
}

// Change the function based on the item type (TODO in case)
int isEqual(Item it1, Item it2) {
    return it1 == it2;
}