/* Scrivere un programma che chiede all'utente di inserire il proprio
 * nome e cognome e che allochi dinamicamente lo spazio necessario a
 * memorizzare i due array di caratteri separatamente.
 *
 * Dopodiché si pongano i due array in una matrice
 *
 * A questo punto implementare le seguenti:
 *
 * 1. una funzione char minimo(char *) che restituisce il carattere di
 * valore minimo (in codifica ASCII) del nome e del cognome
 *
 * [Alternativa] la stessa funzione precedente che lavora sulla matrice
 * di stringhe e quindi char *minimo2(char **) che restituisce l'array di
 * due elementi contenenti il valore minimo (in codifica ASCII) del nome
 * e cognome
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
char minimo(const char *s);
void inserisci_stringa(char **matrice, char *s, int *pos);
char *minimo2(char **matrice);

int main(void) {
    char *nome, *cognome;
    char mn, mc;
    char *minimi;
    int i = 0;
    char **matrice = malloc(2);

    if(!matrice) {
        exit(-1);
    }

    printf("Inserire il proprio nome: ");
    nome = leggi_stringa(25);

    printf("Inserire il proprio cognome: ");
    cognome = leggi_stringa(25);

    printf("\nNome inserito: %s", nome);
    printf("\nCognome inserito: %s", cognome);

    mn = minimo(nome);
    printf("\n\nCarattere minimo del nome: %c", mn);

    mc = minimo(cognome);
    printf("\nCarattere minimo del cognome: %c", mc);

    inserisci_stringa(matrice, nome, &i);
    inserisci_stringa(matrice, cognome, &i);

    minimi = minimo2(matrice);

    printf("\n\nMinimi[0] = %c", minimi[0]);
    printf("\nMinimi[1] = %c", minimi[1]);

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

char minimo(const char *s) {
    char min = s[0];

    while(*s) {
        if(min > *s) {
            min = *s;
        }

        s++;
    }

    return min;
}

void inserisci_stringa(char **matrice, char *s, int *pos) {
    //int lun = strlen(s);

    //matrice[*pos] = malloc(lun + 1);
    matrice[*pos] = malloc(sizeof(char *));

    if(!matrice[*pos]) {
        exit(-1);
    }

    //strcpy(matrice[*pos], s);
    matrice[*pos] = s;

    (*pos)++;
}

char *minimo2(char **matrice) {
    char *minimi;

    minimi = malloc(2);

    if(!minimi) {
        return NULL;
    }

    minimi[0] = minimo(matrice[0]);
    minimi[1] = minimo(matrice[1]);

    return minimi;
}
