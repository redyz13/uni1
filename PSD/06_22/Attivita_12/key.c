#include <stdio.h>
#include "key.h"

void printKey(Key k){
    printf("%d", k);
}

void printKeyAsChar(Key k) {
    printf("%c", k);
}

int isEqual(Key k1, Key k2) {
    return k1 == k2;
}

int isMinus(Key k1, Key k2) {
    return k1 < k2;
}
