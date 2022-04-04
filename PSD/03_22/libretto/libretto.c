#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libretto.h"

struct Libretto {
    char *nome;
    char *cognome;
    int matricola;
    Lista_esami lista_esami;
};

struct Esame {
    char *nome;
    int voto;
};

// Change the function based on the item type
void printLibretto(Libretto data) {
    //printf("%d", data);
}

Libretto new_lib(char *nome, char *cognome, int matricola, Lista_esami lista_esami) {
    Libretto lib = malloc(sizeof(struct Libretto));

    strcpy(lib->nome, nome);
    strcpy(lib->cognome, cognome);
    lib->matricola = matricola;
    // Altra funzione slide
    lib->lista_esami = clone(lista_esami);
}

char *getNome(Libretto);
char *getCognome(Libretto);
int getMatricola(Libretto);
Lista_esami getLista_esami(Libretto);
int getVoto(Lista_esami);

void setVoto(Lista_esami);

float getMedia(Lista_esami);

int cercaEsame(Libretto lib, char *nome_esame) {
    Lista_esami lista_esami, curr, new;
    int i, taglia;

    new = inputItem(nome_esame, -1);

    lista_esami = getLista_esami(lib);

    taglia = sizeList(lista_esami);

    for(i = 0; i < taglia; i++) {
        // Get item slide
        curr = getItem(lista_esami, i);

        if(equal(curr, new)) {
            return getVoto(curr);
        }
    }

    return -1;
}

int isEmpty(Libretto);

int equal(Lista_esami, Lista_esami);
