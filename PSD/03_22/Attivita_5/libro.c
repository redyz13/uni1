#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

struct Libro {
    char *titolo;
    char *editore;
    float prezzo;
    int anno;
};

Libro creaLibro(char *t, char *e, float p, int a) {
    Libro l;
    
    l = malloc(sizeof(struct Libro));
    if(l == NULL) return NULL;

    l->titolo = malloc(strlen(t) + 1);
    l->editore = malloc(strlen(e) + 1);

    if(l->titolo == NULL || l->editore == NULL) {
        free(l);
        return NULL;
    }

    strcpy(l->titolo, t);
    strcpy(l->editore, e);
    
    l->prezzo = p;
    l->anno = a;

    return l;
}

char *getTitolo(Libro l) { 
    return l->titolo;
}

char *getEditore(Libro l) { 
    return l->editore;
}

int getAnno(Libro l) {
    return l->anno;
} 

float getPrezzo(Libro l) {
    return l->prezzo;
}

float sconto(Libro *l, float percentuale){
    float p, tot;
    
    p = (*l)->prezzo;

    tot = p - (p * (percentuale / 100));
    
    (*l)->prezzo = tot;

    return tot;
}

void aggiornaAnno(Libro *l, int anno) {
	(*l)->anno = anno;
}

void printLibro(Libro l) {
    if(l == NULL) return;

    printf("Titolo: %s\n", l->titolo);
    printf("Editore: %s\n",l->editore); 
    printf("Prezzo: %.2f\n", l->prezzo);
    printf("Anno: %d\n\n", l->anno);
}

void freeLibro(Libro l) {
    free(l->titolo);
    free(l->editore);
    free(l);
}
