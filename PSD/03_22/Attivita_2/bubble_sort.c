/* Creare una funzione void ordina(char *) che ordini
 * i caratteri del nome e del cognome con l'algoritmo
 * di ordinamento BubbleSort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
void copia_stringa(char *s1, const char *s2);
// Bubble sort
void ordina(char *s1);

int main(void) {
    char *nome, *cognome;

    printf("Inserire il proprio nome: ");
    nome = leggi_stringa(25);

    printf("Inserire il proprio cognome: ");
    cognome = leggi_stringa(25);

    printf("\nNome inserito: %s", nome);
    printf("\nCognome inserito: %s", cognome);

    ordina(nome);
    ordina(cognome);

    printf("\n\nNome ordinato: %s", nome);
    printf("\nCognome ordinato: %s", cognome);

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

    *pi = '\0';
}

// Bubble sort
void ordina(char *s1) {
    int i, j, lenght;
    int tmp;

    lenght = strlen(s1);

    for(i = 0; i < lenght; i++) {
        for(j = 0; j < (lenght - 1 - i); j++) {
            if(s1[j] > s1[j+1]) {
                tmp = s1[j];
                s1[j] = s1[j+1];
                s1[j+1] = tmp;
            }
        }
    }
}
