#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include "libro.h"

#define BUFFSIZE 100

Libro libropiuvecchio(Libro *biblioteca, int n);

Libro libromenocostoso(Libro *biblioteca, int n);

Libro *ricercaeditore(Libro *biblioteca, const char *editore, int n, int *index);

int scontalibri(Libro* biblioteca, int anno, float percentuale, int n);

Libro *scartoMinore(Libro *biblioteca, int n);

float costototale(Libro *biblioteca, int anno, int n);

void leggi_stringa(char *s);

int main(void) {
    Libro *biblioteca, *libri_editore;
    char tit[100];
    char ed[50];
    float pr;
    int an;
    int n, i;

    printf("Dammi il numero di libri in biblioteca da inserire: ");
    scanf("%d", &n);
    getchar();

    putchar('\n');

    biblioteca = malloc(sizeof(Libro) * n);
    if(biblioteca == NULL) return -1;

    for(i = 0; i < n; i++){
        printf("Inserisci titolo: ");
        leggi_stringa(tit);

        printf("Inserisci editore: ");
        leggi_stringa(ed);
        
        printf("Inserisci prezzo: ");
        scanf("%f", &pr);
        getchar();

        printf("Inserisci anno: ");
        scanf("%d", &an);
        getchar();

        biblioteca[i] = creaLibro(tit, ed, pr, an);
        
        putchar('\n');
    }

    for(i = 0; i < n; i++) { 
        printLibro(biblioteca[i]);
    }

    printf("Ricerca del libro più vecchio:\n\n");
    Libro vecchio = libropiuvecchio(biblioteca, n);
    printLibro(vecchio);

    printf("Ricerca del libro meno costoso:\n\n");
    Libro meno_costoso = libromenocostoso(biblioteca, n);
    printLibro(meno_costoso);

    printf("Inserisci editore del quale ricercare libri: ");

    leggi_stringa(ed);

    int index;

    libri_editore = ricercaeditore(biblioteca, ed, n, &index);

    printf("\nLibri di %s:\n", ed);

    for(i = 0; i < index; i++) {
        printLibro(libri_editore[i]);
    }

    printf("Inserisci l'anno dei libri da scontare: ");
    scanf("%d", &an);
    printf("Inserisci la percentuale di sconto: ");
    scanf("%f", &pr);

    scontalibri(biblioteca, an, pr, n);

    printf("\nLibri dopo sconti:\n\n");

    for(i = 0; i < n; i++) {
        printLibro(biblioteca[i]);
    }

    Libro *scarto_minore;
    scarto_minore = scartoMinore(biblioteca, n);

    printf("\nLibri con scarto di prezzo minore:\n\n");
    printLibro(scarto_minore[0]);
    printLibro(scarto_minore[1]);

    printf("Inserisci l'anno dei libri di cui calcolare il prezzo totale: ");
    scanf("%d", &an);

    float tot;

    tot = costototale(biblioteca, an, n);

    printf("\nCosto totale dei libri dell'anno %d: %.2f\n", an, tot);

    for(i = 0; i < n; i++) {
        freeLibro(biblioteca[i]);
    }

    free(scarto_minore);
    free(libri_editore);
    free(biblioteca);

    return 0;
}

void leggi_stringa(char *s) {
    char s1[BUFFSIZE];
    int ch, i = 0;

    while((ch = getchar()) != '\n') {
        if(i < BUFFSIZE) {
            s1[i++] = ch;
        }
    }

    s1[i] = '\0';

    strcpy(s, s1);
}

Libro libropiuvecchio(Libro *biblioteca, int n) {
    int vecchio = getAnno(biblioteca[0]);
    int anno, index = 0;

    for(int i = 1; i < n; i++) {
        anno = getAnno(biblioteca[i]);

        if(vecchio > anno) {
            vecchio = anno;
            index = i;
        }
    }

    return biblioteca[index];
}

Libro libromenocostoso(Libro *biblioteca, int n) {
    int meno_costoso = getPrezzo(biblioteca[0]);
    int prezzo, index = 0;

    for(int i = 1; i < n; i++) {
        prezzo = getPrezzo(biblioteca[i]);

        if(meno_costoso > prezzo) {
            meno_costoso = prezzo;
            index = i;
        }
    }

    return biblioteca[index];
}

Libro *ricercaeditore(Libro *biblioteca, const char *editore, int n, int *index) {
    Libro *libri_editore;
    char *ed;
    *index = 0;

    libri_editore = malloc(sizeof(Libro) * n);
    if(libri_editore == NULL) return NULL;

    for(int i = 0; i < n; i++) {
        ed = getEditore(biblioteca[i]);

        if(!strcmp(ed, editore)) {
            libri_editore[*index] = biblioteca[i];
            (*index)++;
        }
    }

    libri_editore = realloc(libri_editore, sizeof(Libro) * (*index));
    if(libri_editore == NULL) return NULL;

    return libri_editore;
}

int scontalibri(Libro* biblioteca, int anno, float percentuale, int n) {
    int an;

    for(int i = 0; i < n; i++) {
        an = getAnno(biblioteca[i]);

        if(an == anno) {
            sconto(&biblioteca[i], percentuale);
        }
    }

    return 1;
}

Libro *scartoMinore(Libro *biblioteca, int n) {
    Libro *scarto_minore;
    float p1, p2;
    float scarto, min;
    int pos1 = 0, pos2 = 1;

    scarto_minore = malloc(sizeof(Libro) * 2);
    if(scarto_minore == NULL) return NULL;

    p1 = getPrezzo(biblioteca[0]);
    p2 = getPrezzo(biblioteca[1]);

    min = p1 - p2; 

    if(min < 0) min = min * -1; 

    for(int i = 1; i < n - 1; i++) {
        p1 = getPrezzo(biblioteca[i]);

        for(int j = i + 1; j < n; j++) {
            p2 = getPrezzo(biblioteca[j]);

            scarto = p1 - p2;

            if(scarto < 0) scarto = scarto * -1;

            if(min > scarto) {
                min = scarto;
                pos1 = i;
                pos2 = j;
            }
        }
    }

    scarto_minore[0] = biblioteca[pos1];
    scarto_minore[1] = biblioteca[pos2];

    return scarto_minore;
}

float costototale(Libro *biblioteca, int anno, int n) {
    float tot = 0;
    int an;

    for(int i = 0; i < n; i++) {
        an = getAnno(biblioteca[i]);

        if(anno == an) {
            tot += getPrezzo(biblioteca[i]);
        }
    }

    return tot;
}
