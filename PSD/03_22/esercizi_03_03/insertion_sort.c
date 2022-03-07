/* Creare una funzione void ordina(char *) che ordini
 * i caratteri del nome e del cognome con l'algoritmo
 * di ordinamento InsertionSort 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
void copia_stringa(char *s1, const char *s2);
// Insertion sort
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

// Insertion sort
void ordina(char *s1) {
    int i, j, lenght;
    int key;

    lenght = strlen(s1);

    for(i = 1; i < lenght; i++) {
        key = s1[i];
        j = i - 1;

        while(j >= 0 && s1[j] > key) {
            s1[j+1] = s1[j];
            j--;
        }

        s1[j+1] = key;
    }
}
