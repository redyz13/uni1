#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canzone.h"

struct Item {
    char *titolo;
    char *cantante;
    int durata;
};

Canzone creaCanzone(char *ti, char *ca, int du) {
    Canzone c;

    c = malloc(sizeof(struct Item));
    if(c == NULL) return NULL;

    c->titolo = malloc(strlen(ti) + 1);
    if(c->titolo == NULL) {
        free(c);
        return NULL;
    }

    c->cantante = malloc(strlen(ca) + 1);
    if(c->cantante == NULL) {
        free(c->titolo);
        free(c);
        return NULL;
    }

    strcpy(c->titolo, ti);
    strcpy(c->cantante, ca);

    c->durata = du;

    return c;
}

void printCanzone(Canzone c) {
    printf("\nTitolo: %s", c->titolo);
    printf("\nCantante: %s", c->cantante);
    printf("\nDurata: %d secondi\n", c->durata);
}

void freeCanzone(Canzone c) {
    if(c == NULL) return;

    free(c->titolo);
    free(c->cantante);
    free(c);
}
