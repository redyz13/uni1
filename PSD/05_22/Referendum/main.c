#include <stdio.h>
#include "referendum.h"

int main(void) {
    Referendum r;
    
    r = creaRef();
    
    Seggio seggio1, seggio2;
    Scheda scheda1, scheda2;
    
    scheda1 = creaScheda(1, 2, 3, 4, 5, 6);
    seggio1 = creaSeggio(1, scheda1);
    
    scheda2 = creaScheda(7, 8, 9, 10, 11, 12);
    seggio2 = creaSeggio(2, scheda2);
    
    r = insertSeggio(r, seggio1);
    r = insertSeggio(r, seggio2);
    
    printf("[Lista seggi]\n\n");
    
    printSeggi(r);
    
    completeRef(r) ? printf("La lista dei seggi è completa\n")
                   : printf("La lista dei seggi non è completa\n");

	stampaReport(r);

    printf("\n--- Esito del referendum ---\n");

    noSiRef(r) ? printf("\nApprovato\n")
               : printf("\nNon approvato\n");
    
    return 0;
}