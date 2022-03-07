/* Creare una funzione char *incastona(char *, char *) che produce una nuova
 * stringa secondo la seguente regola: la più piccola delle due va
 * incastonata nella più lunga sostituendo i caratteri di questa ultima
 * Esempio: a = "fabio" b = "narducci" restituirà in output la stringa
 * c = "nfabioci" (nota. quando la stringa più lunga ha un numero pari di
 * caratteri, la stringa più corta viene incastonata al centro a meno di un
 * carattere a sx o dx)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
void copia_stringa(char *s1, const char *s2);
char *incastona(char *s1, char *s2);

int main(void) {
    char *nome, *cognome;
    char *incast;

    printf("Inserire il proprio nome: ");
    nome = leggi_stringa(25);

    printf("Inserire il proprio cognome: ");
    cognome = leggi_stringa(25);

    printf("\nNome inserito: %s", nome);
    printf("\nCognome inserito: %s", cognome);

    incast = incastona(nome, cognome);

    printf("\nStringa incastonata: %s", incast);

    return 0;
}

char *leggi_stringa(int buff) {
    char *s;
    char tmp[buff+1];
    int lun;
    int ch, i = 0;

    while((ch = getchar()) != '\n') {
        if(i < buff) {
            tmp[i++] = ch;
        }
    }

    tmp[i] = '\0';

    lun = strlen(tmp);

    s = malloc(lun + 1);

    if(!s) {
        return NULL;
    }

    strcpy(s, tmp);

    return s;
}

void copia_stringa(char *s1, const char *s2) {
    char *pi = s1;

    while(*s2) {
        *pi++ = *s2++;
    }

    // Terminatore non necessario in quest'implementazione
    // *pi = '\0';
}

char *incastona(char *s1, char *s2) {
    char *incast;
    int lun1, lun2;

    lun1 = strlen(s1);
    lun2 = strlen(s2);

    if(lun1 > lun2) {
        incast = malloc(lun1 + 1);

        copia_stringa(incast, s1);

        // Aggiunta del terminatore
        incast[lun1] = '\0';

        if(lun1 % 2 == 0) {
            // Passo al carattere successivo per l'incastonamento
            // con cifre pari (incast + 1) e incastono la stringa
            // corta nella stringa lunga
            copia_stringa(incast+1, s2);

            // Il terminatore è già presente, perché copiato dalla stringa lunga
        }
        else {
            // Incastono la stringa corta a partire dal primo carattere
            // nella stringa lunga
            copia_stringa(incast, s2);
        }
    }
    else if(lun2 > lun1){
        incast = malloc(lun2 + 1);

        copia_stringa(incast, s2);

        incast[lun2] = '\0';

        if(lun2 % 2 == 0) {
            copia_stringa(incast+1, s1);
        }
        else {
            copia_stringa(incast, s1);
        }
    }

    return incast;
}
