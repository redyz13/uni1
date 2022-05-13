#include <stdio.h>
#include "list.h"

List sottolista(List l, List subl, int n, int m);

int main(void) {
    List l;

    l = newList();

    addFirst(&l, 10);
    addFirst(&l, 20);
    addFirst(&l, 30);
    addFirst(&l, 40);
    addFirst(&l, 50);
    addFirst(&l, 100);

    printList(l);

    putchar('\n');
    
    List sub = newList();
    
    sub = sottolista(l, sub, 2, 4);
    
    printf("Sottolista:\n\n");
    
    printList(sub);

    return 0;
}

/*
    Precondizioni:
        1. n < m
*/
List sottolista(List l, List subl, int n, int m) {
    // Passo base
    if (n > m) return reverseList(subl);
    
    // Passo ricorsivo
    addFirst(&subl, getPos(l, n));
    
    sottolista(l, subl, n + 1, m);
}