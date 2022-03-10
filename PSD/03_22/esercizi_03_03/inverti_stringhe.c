/* Creare una funzione void inveti(char **) che prende la matrice
 * e rimpiazza la stringa del nome con quella del cognome e
 * viceversa (in sostanza uno swap delle due stringhe)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
void copia_stringa(char *s1, const char *s2);
void inserisci_stringa(char **matrice, char *s, int *pos);
void inverti(char **matrice);

int main(void) {
    char *nome, *cognome;
    int i = 0;
    char *matrice[2];

    printf("Inserire il proprio nome: ");
    nome = leggi_stringa(25);

    printf("Inserire il proprio cognome: ");
    cognome = leggi_stringa(25);

    printf("\nNome inserito: %s", nome);
    printf("\nCognome inserito: %s", cognome);

    inserisci_stringa(matrice, nome, &i);
    inserisci_stringa(matrice, cognome, &i);
    
    inverti(matrice);

    printf("\n\nNome inserito nella matrice: %s", matrice[0]);
    printf("\nCognome inserito nella matrice: %s", matrice[1]);

    printf("\n\nNome inserito nella matrice (invertito con cognome): %s", matrice[0]);
    printf("\nCognome inserito nella matrice (invertito con nome): %s", matrice[1]);

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

void inserisci_stringa(char **matrice, char *s, int *pos) {
    matrice[*pos] = s;

    (*pos)++;
}

void inverti(char **matrice) {
    char *tmp;

    tmp = matrice[0];
    matrice[0] = matrice[1];
    matrice[1] = tmp;
}
