#include <stdio.h>
#include "key.h"

// Change the function based on the item type (TODO in case)
void printItem(Key it){
    printf("%d", it);
}

/* Change the function based on the item type (TODO in case)
*  You will need this function only if the item is allocated
*/
void freeItem(Key it) {
    ;
}

// Change the function based on the item type (TODO in case)
int isEqual(Key it1, Key it2) {
    return it1 == it2;
}

int isMinus(Key it1, Key it2) {
    return it1 < it2;
}
