/* Scrivere un programma che prende in input una stringa da riga di comando e 
 * attraverso una funzione ?? vocali_consonanti(char*) separi tutte le consonanti 
 * dalle vocali memorizzandoli in due array di caratteri distinti restituiti in 
 * output e mostrati su standard output (il tipo restituito dalla funzione non è indicato 
 * ed è a scelta del programmatore)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
void copia_stringa(char *s1, const char *s2);

int main(int argc, char **argv) {
    char *concat;

    if(argc < 2) {
        printf("Utilizzo: <%s stringa>\n", argv[0]);
    }
    else {
        printf("Stringa inserita: %s", argv[1]);
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
