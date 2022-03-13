/* Scrivere un programma che implementa la funzione char *merge(char*, char*) 
 * che prende da riga di comando due stringhe e produce una nuova stringa
 * che è il risultato della concatenazione delle due date in input. 
 * Il risultato va mostrato su standard output
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
void copia_stringa(char *s1, const char *s2);
char *merge(const char *s1, const char *s2);

int main(int argc, char **argv) {
    char *concat;

    if(argc < 3) {
        printf("Utilizzo: <%s nome cognome>\n", argv[0]);
    }
    else {
        printf("Nome inserito: %s", argv[1]);
        printf("\nCognome inserito: %s", argv[2]);

        concat = merge(argv[1], argv[2]);

        printf("\nConcatenazione di nome e cognome: %s", concat);
    }

    return 0;
}

void copia_stringa(char *s1, const char *s2) {
    char *pi = s1;

    while(*s2) {
        *pi++ = *s2++;
    }

    *pi = '\0';
}

char *merge(const char *s1, const char *s2) {
    char *p;
    char *pi;

    p = malloc(strlen(s1) + strlen(s2) + 1);

    if(!p) {
        exit(-1);
    }

    pi = p;

    copia_stringa(pi, s1);

    while(*pi)
        pi++;

    copia_stringa(pi, s2);

    return p;
}
