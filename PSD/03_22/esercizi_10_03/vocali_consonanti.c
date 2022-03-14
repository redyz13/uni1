/* Scrivere un programma che prende in input una stringa da riga di comando e 
 * attraverso una funzione ?? vocali_consonanti(char*) separi tutte le consonanti 
 * dalle vocali memorizzandoli in due array di caratteri distinti restituiti in 
 * output e mostrati su standard output (il tipo restituito dalla funzione non è indicato 
 * ed è a scelta del programmatore)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *leggi_stringa(int buff); 
int isvocal(const char c);
char **vocali_consonanti(const char *s);

int main(int argc, char **argv) {
    char **matrice;

    if(argc < 2) {
        printf("Utilizzo: <%s stringa>\n", argv[0]);
    }
    else {
        printf("Stringa inserita: %s", argv[1]);

        matrice = vocali_consonanti(argv[1]);

        printf("\n\nVocali: %s", matrice[0]);
        printf("\nConsonati: %s\n", matrice[1]);
    }

    return 0;
}

int isvocal(const char c) {
    const char vocali[] = {'a', 'e', 'i', 'o', 'u'};
    int i;

    for(i = 0; i < 5; i++) {
        if(c == vocali[i]) {
            return 1;
        }
    }

    return 0;
}

char **vocali_consonanti(const char *s) {
    int i = 0, n_vocali = 0, n_consonanti = 0;
    int lun = strlen(s);

    char **matrice = malloc(sizeof(char *) * 2);
    char *a_vocali = malloc(lun + 1);
    char *a_consonanti = malloc(lun + 1);

    if(!matrice || !a_vocali || !a_consonanti) {
        exit(-1);
    }

    while(i < lun) {
        if(isalpha(s[i]) && isvocal(s[i])) {
            a_vocali[n_vocali] = s[i];
            n_vocali++;
        }
        else if(isalpha(s[i])){
            a_consonanti[n_consonanti] = s[i];
            n_consonanti++;
        }

        i++;
    }

    a_vocali[n_vocali] = '\0';
    a_consonanti[n_consonanti] = '\0';

    a_vocali = realloc(a_vocali, n_vocali + 1);
    a_consonanti = realloc(a_consonanti, n_consonanti + 1);

    if(!a_vocali || !a_consonanti) {
        exit(-1);
    }

    matrice[0] = a_vocali;
    matrice[1] = a_consonanti;

    return matrice;
}
