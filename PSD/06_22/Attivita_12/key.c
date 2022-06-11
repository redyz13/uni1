#include <stdio.h>
#include "key.h"

void printKey(Key it){
    printf("%d", it);
}

int isEqual(Key k1, Key k2) {
    return k1 == k2;
}

int isMinus(Key k1, Key k2) {
    return k1 < k2;
}
