#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ebreo.h"
#define MAX_LUN 40

void leggi_stringa(char str[]) {
    int n;
    
    fgets(str, MAX_LUN+2, stdin);

    n = strlen(str);

    if(str[n-1] == '\n') str[n-1] = '\0';
}

ebreo *alloca_ebreo(ebreo *e) {
    e = malloc(sizeof(ebreo));

    if(!e) return NULL;

    return e;
}

ebreo *censisci_ebrei(ebreo *ebreo) {
    ebreo = alloca_ebreo(ebreo);
    char nome[MAX_LUN + 1], cognome[MAX_LUN + 1];
    int anni, id;

    printf("Inserire il nome dell'ebreo: ");
    leggi_stringa(nome);
    printf("Inserire il cognome dell'ebreo: ");
    leggi_stringa(cognome);
    printf("Inserire l'età dell'ebreo: ");
    scanf("%d", &anni);
    printf("Con quale numero vuoi timbrarlo?: ");
    scanf("%d", &id);
    printf("\n");

    ebreo->nome = malloc(strlen(nome) + 1); 

    if(!ebreo->nome) return NULL;

    strcpy(ebreo->nome, nome);

    ebreo->cognome = malloc(strlen(cognome) + 1); 

    if(!ebreo->cognome) return NULL;

    strcpy(ebreo->cognome, cognome);
    ebreo->anni = anni;

    ebreo->id = id;

    return ebreo;
}

void elenca_ebrei(ebreo *ebreo[], int index) {
    int i;

    for(i = 0; i <= index - 1; i++)
        print_ebreo(ebreo[i]);
}

void print_ebreo(ebreo *ebreo) {
    printf("Nome: %s", ebreo->nome);
    printf("\nCognome: %s", ebreo->cognome);
    printf("\nAnni: %d", ebreo->anni);
    printf("\nId: %d\n\n", ebreo->id);
}

void ebrei_default(ebreo *ebreo[], int *index) {
    ebreo[0] = build_ebreo("Angelo", "De Luca", 19, 669);   
    ebreo[1] = build_ebreo("Vittorio Maria", "Borrello", 23, 880); 
    ebreo[2] = build_ebreo("Pierpaolo", "Pastore", 23, 890); 
    ebreo[3] = build_ebreo("Luca", "Casillo", 19, 190); 
    ebreo[4] = build_ebreo("Rosalia", "Fortino", 22, 290); 
    ebreo[5] = build_ebreo("Frank", "Lo Schiavo", 34, 790); 
    *index = 6;
}

ebreo *build_ebreo(const char nome[], const char cognome[], int anni, int id) {
    ebreo *e = NULL;
    e = alloca_ebreo(e);

    e->nome = malloc(strlen(nome) + 1); 

    if(!e->nome) return NULL;

    strcpy(e->nome, nome);

    e->cognome = malloc(strlen(cognome) + 1); 

    if(!e->nome) return NULL;

    strcpy(e->cognome, cognome);
    e->anni = anni;
    e->id = id;

    return e;
}

int metti_nel_forno(ebreo *ebreo[], int *index) {
    int j;

    j = cerca_ebreo(ebreo, *index);

    if(j == -1)
        return 0;

    free(ebreo[j]->nome);
    free(ebreo[j]->cognome);
    free(ebreo[j]);
    
    for(; j < *(index) - 1; j++) {
        ebreo[j] = ebreo[j+1];
    }

    (*index)--;

    return 1;
}

int cerca_ebreo(ebreo *ebreo[], int index) {
    int id, i;

    printf("Inserisci l'id dell'ebreo: ");
    scanf("%d", &id);
    printf("\n");

    for(i = 0; i <= index - 1; i++) {
        if(ebreo[i]->id == id) {
            return i;
        }
    }

    return -1;
}