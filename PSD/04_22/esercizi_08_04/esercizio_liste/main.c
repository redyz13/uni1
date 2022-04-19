#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List list;
    int x;

    list = newList();

    // Inserimento in input di 5 elementi
    for(int i = 0; i < 5; i++) {
        input_item(&x);
        addFirst(list, x);
    }

    // Inverte la lista
    list = reverseList(list);

    putchar('\n');

    // Stampa la lista
    printList(list);

    // Cerca l'elemento 55
    contains(list, 55) ? (printf("\nL'elemento 55 è presente\n"))
                       : (printf("\nL'elemento 55 non è presente\n"));

    // Cerca la posizione dell'elemento 25
    int i = indexOf(list, 25);

    i >= 0 ? (printf("\nL'elemento 25 è presente alla posizione %d\n", i))
           : (printf("\nL'elemento 25 non è presente\n"));


    // Switch a coppie della lista
    switchCoppie(list);

    printf("\nSwitch a coppie della lista\n");

    putchar('\n');

    printList(list);

    printf("\nEliminazione dell'elemento centrale (in caso esista)\n");

    eliminaCentro(list);

    putchar('\n');

    printList(list);

    freeList(list);

    return 0;
}
