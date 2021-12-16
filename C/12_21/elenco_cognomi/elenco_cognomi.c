#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define PERS 5

int main() {
    Persona *lista[PERS];
    Persona **elenco_con_cognomi;
    int index = 0, s, i;
    int found, cognomi = 0;

    do {
        printf("Elenco persone\n\n1. Elenca persone\n2. Aggiungi persona"
                "\n3. Cerca per cf\n4. Cerca per nome e cognome\n5. Crea sottoelenco per cognome"
                "\n0. Esci\n");
        printf("\nSelezione: ");
        scanf("%d", &s);
        while(getchar() != '\n');
        printf("\n");

        switch(s) {
            case 1:
                printf("[Lista persone]\n\n");
                elenca_persone(lista, index);
                break;
            case 2:
                lista[index] = inserisci_persona(&index);
                printf("[Persona aggiunta]\n\n");
                break;
            case 3:
                found = cerca_cf(lista, index);

                if(found != -1) {
                    printf("[Persona trovata]\n\n");
                    print_persona(lista[found]);
                }
                else {
                    printf("[Persona non trovata]\n\n");
                }
                break;
            case 4:
                found = cerca_nm(lista, index);

                if(found != -1) {
                    printf("[Persona trovata]\n\n");
                    print_persona(lista[found]);
                }
                else {
                    printf("[Persona non trovata]\n\n");
                }

                break;
            case 5:
                elenco_con_cognomi = crea_elenco(lista, index, &cognomi);

                if(elenco_con_cognomi != NULL) {
                    printf("[Elenco creato]\n\n");

                    fflush(stdout);

                    for(i = 0; i < cognomi; i++) {
                        print_persona(elenco_con_cognomi[i]);
                    }

                    elimina_elenco(elenco_con_cognomi, &cognomi);
                    free(elenco_con_cognomi);

                    /* Dopo la visualizzazione dell'elenco creato lo
                    *  dealloco, così da poterne creare altri
                    */
                }
                else {
                    printf("[Nessun cognome trovato]\n\n");
                }

                break;
            case 0:
                elimina_elenco(lista, &index); // Non necessario
                return 0;
        }

    } while(1);

    return 0;
}