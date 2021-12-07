#include <stdio.h> 
#include <stdlib.h>
#include "ebreo.h"
#define EBREI 30

int main() {
    int s, index = 0, found;
    ebreo *ebreo[EBREI];

    ebrei_default(ebreo, &index);

    do {
        printf("Soluzione finale\n\n1. Elenca ebrei\n2. Censisci ebrei\n3. Metti nel forno"
               "\n4. Cerca ebreo\n0. Esci\n");
        printf("\nSelezione: ");
        scanf("%d", &s);
        while(getchar() != '\n'); // Usare ogni volta che si usa una scanf prima di fgets
        printf("\n");

        switch(s) {
            case 1:
                printf("[Ebrei censiti]\n\n");
                elenca_ebrei(ebreo, index);
                break;
            case 2:
                ebreo[index] = censisci_ebrei(ebreo[index]);
                index++;
                printf("[Ebreo censito]\n\n");
                break;
            case 3:
                if(metti_nel_forno(ebreo, &index)) {
                    printf("[Ebreo eliminato]\n\n");
                }
                else {
                    printf("[Ebreo non schedato]\n\n");
                }
                break;
            case 4:
                found = cerca_ebreo(ebreo, index);

                if(found != -1) {
                    printf("[Ebreo trovato]\n\n");
                    print_ebreo(ebreo[found]);
                }
                else {
                    printf("[Ebreo non trovato]\n\n");
                }
                break;
            case 0:
                exit(0);
        }

    }while(1938);

    return 0;
}
