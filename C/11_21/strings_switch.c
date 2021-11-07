#include <stdio.h>
#include <string.h>

#define BADKEY -1
#define A1 1
#define A2 2
#define B1 3
#define B2 4

/* typedef definisce un alias per la struct (per evitare di dover 
*  riscrivere struct nome_struct)
*/
typedef struct { char *key; int val; } t_symstruct;

/* definisco un array di struct di tipo struct */
static t_symstruct lookuptable[] = {
    { "A1", A1 }, { "A2", A2 }, { "B1", B1 }, { "B2", B2 }
};

/* permette di capire il numero di struct di lookuptable
*  dimensione in byte di *key = 4 e di val = 4 (dimensione
*  di t_stymstruct = 8)
*  ogni t_stymstruct vale 8 byte, la dimensione di lookuptable
*  sarà quindi di 32 essendoci 4 t_stymstruct
*  sizeof(lookuptable)/sizeof(t_symstruct) è uguale a 4 (NKEYS = 4)
*/
#define NKEYS (sizeof(lookuptable)/sizeof(t_symstruct))


/* creo un puntatore *sym a cui do l'indirizzo di lookuptable[i]
*  utilizzo l'operatore -> per fare riferimento a una specifica
*  variabile della struct e faccio lo strcmp per verificare che
*  la key inserita dell'utente sia uguale a una di quelle della struct
*/
int keyfromstring(char *key) {
    int i;

    for(i = 0; i < NKEYS; i++) {
        t_symstruct *sym = &lookuptable[i];
        if(!strcmp(sym->key, key))
            return sym->val;
    }

    return BADKEY;
}

int main() {
    char somestring[] = "C1";

    switch (keyfromstring(somestring)) {
        case A1: printf("Troia1"); break;
        case A2: printf("Troia2"); break;
        case B1: printf("Troia3"); break;
        case B2: printf("Troia4"); break;
        case BADKEY: printf("Vaffanculo"); 
    }

    return 0;
}