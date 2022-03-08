/* Creare una funzione void crea(char **) che aggiunge una terza 
*  stringa alla matrice composta dai primi tre caratteri del nome
*  e gli ultimi tre del cognome
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
void copia_stringa(char *s1, const char *s2, int nchars);
void inserisci_stringa(char **matrice, char *s, int *pos);
void crea(char **matrice, int *pos);

int main(void) {
    char *nome, *cognome;
    int i = 0;
    char *matrice[3];

    printf("Inserire il proprio nome: ");
    nome = leggi_stringa(25);

    printf("Inserire il proprio cognome: ");
    cognome = leggi_stringa(25);

    printf("\nNome inserito: %s", nome);
    printf("\nCognome inserito: %s", cognome);

    inserisci_stringa(matrice, nome, &i);
    inserisci_stringa(matrice, cognome, &i);
    
    crea(matrice, &i);

    printf("\n\nNome inserito nella matrice: %s", matrice[0]);
    printf("\nCognome inserito nella matrice: %s", matrice[1]);

    printf("\n\nNuova stringa inserita nella matrice: %s", matrice[2]);

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

void copia_stringa(char *s1, const char *s2, int nchars) {
    char *pi = s1;
    int i = 0;

    while(*s2 && i < nchars) {
        *pi++ = *s2++;
        i++;
    }

    *pi = '\0';
}

void inserisci_stringa(char **matrice, char *s, int *pos) {
    matrice[*pos] = s;

    (*pos)++;
}

void crea(char **matrice, int *pos) {
    char *nuova_stringa = malloc(6 + 1);
    char *pi;
    int lun;

    if(!nuova_stringa) {
        exit(-1);
    }

    pi = nuova_stringa;

    // Copia dei primi tre caratteri del nome
    copia_stringa(pi, matrice[0], 3);

    // Scorro la stringa fino a trovare il carattere terminatore
    while(*pi)
        pi++;

    // Copia degli ultimi tre caratteri del cognome
    lun = strlen(matrice[1]);

    // Sommo la lunghezza della stringa per scorrere il puntatore 
    // alla fine della stringa e sottraggo 3 per lasciare gli ultimi
    // tre caratteri da copiare
    copia_stringa(pi, (matrice[1] + lun - 3), 3);

    inserisci_stringa(matrice, nuova_stringa, pos);
}
