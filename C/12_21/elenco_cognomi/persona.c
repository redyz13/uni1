#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "persona.h"

#define MAXLUN 30

void elimina_persona(Persona *p) {
    free(p->nome);
    free(p->cognome);
    free(p);
}

Persona *inserisci_persona(int *index) {
    char nome[MAXLUN+1], cognome[MAXLUN+1];
    char codice_fiscale[16+1];

    Persona *p;

    p = xmalloc(sizeof(Persona));

    printf("Inserire il nome della persona: ");
    leggi(nome);
    
    p->nome = xmalloc(sizeof(strlen(nome) + 1));
    strcpy(p->nome, nome);

    printf("Inserire il cognome della persona: ");
    leggi(cognome);

    p->cognome = xmalloc(sizeof(strlen(cognome) + 1));
    strcpy(p->cognome, cognome);

    printf("Inserire l'età della persona: ");
    scanf("%d", &p->anni);

    while(getchar() != '\n');

    printf("Inserire il codice fiscale della persona: ");
    do {
        leggi(codice_fiscale);

        if(check_codice(codice_fiscale)) {
            break;
        }

        printf("\nFormato non corretto!\nReinserire: ");
    } while(check_codice(codice_fiscale) != 1);

    strcpy(p->codice_fiscale, codice_fiscale);

    printf("\n");

    (*index)++;

    return p;
}

void leggi(char *str) { 
    int len;

    fgets(str, MAXLUN + 1, stdin);

    len = strlen(str);
    
    if(str[len-1] == '\n')
        str[len-1] = '\0';
}

void *xmalloc(size_t bytes) {
    void *p;

    p = malloc(bytes);

    if(!p) {
        fprintf(stderr, "Error...byee <3\n");
        exit(-1);
    }

    return p;
}

void elenca_persone(Persona **lista, int index) {
    int i;

    for(i = 0; i < index; i++) {
        print_persona(lista[i]);
    }
}

void print_persona(Persona *p) {
    printf("Nome: %s", p->nome);
    printf("\nCognome: %s", p->cognome);
    printf("\nAnni: %d", p->anni);
    printf("\nCodice fiscale: %s\n\n", p->codice_fiscale);
}

int cerca_cf(Persona **lista, int index) {
    char codice_fiscale[16+1];
    int i;

    printf("Inserire il codice fiscale della persona da cercare: ");
    leggi(codice_fiscale);
    printf("\n");

    for(i = 0; i < index; i++) {
        if(!(strcmp(lista[i]->codice_fiscale, codice_fiscale))) {
            return i;
        }
    }

    return -1;
}

int cerca_persona(Persona **lista, char *codice_fiscale, int index) {
    int i;

    for(i = 0; i < index; i++) {
        if(!(strcmp(lista[i]->codice_fiscale, codice_fiscale))) {
            return i;
        }
    }

    return -1;
}

int cerca_persona_cognome(Persona **lista, char *cognome, int index, int *current_index) {
    int i;

    for(i = *current_index; i < index; i++) {
        if(!(strcmp(lista[i]->cognome, cognome))) {
            return i;
        }
    }

    return -1;
}

int check_codice(char *str) {
    int c = 1;

    // Controllo lettere
    c = c && isalpha(str[0]);
    c = c && isalpha(str[1]);
    c = c && isalpha(str[2]);
    c = c && isalpha(str[3]);
    c = c && isalpha(str[4]);
    c = c && isalpha(str[5]);
    c = c && isalpha(str[8]);
    c = c && isalpha(str[11]);
    c = c && isalpha(str[15]);

    // Controllo caratteri numerici
    c = c && isdigit(str[6]);
    c = c && isdigit(str[7]);
    c = c && isdigit(str[9]);
    c = c && isdigit(str[10]);
    c = c && isdigit(str[12]);
    c = c && isdigit(str[13]);
    c = c && isdigit(str[14]);

    if(c) return 1;

    return 0;
}

int cerca_nm(Persona **lista, int index) {
    char nome[MAXLUN+1], cognome[MAXLUN+1];
    char nome_p[MAXLUN+1], cognome_p[MAXLUN+1];
    //char search[(MAXLUN+1)*2];
    //char tmp[(MAXLUN+1)*2];
    int i;

    printf("Inserire il nome della persona: ");
    leggi(nome);
    
    printf("Inserire il cognome della persona: ");
    leggi(cognome);

    //strcat(search, nome);
    //strcat(search, cognome);

    printf("\n");

    for(i = 0; i < index; i++) {
        //strcat(tmp, lista[i]->nome);
        //strcat(tmp, lista[i]->cognome);
        strcpy(nome_p, lista[i]->nome);
        strcpy(cognome_p, lista[i]->cognome);

        if(!(strcmp(nome_p, nome))) {
            if(!(strcmp(cognome_p, cognome))) {
                return i;
            }
        }
    }

    return -1;
}

Persona **crea_elenco(Persona **lista, int index, int *cognomi) {
    Persona **elenco_con_cognomi;
    char cognome[MAXLUN+1];
    char nome[MAXLUN+1];
    int i, j = 0, found = 0;

    elenco_con_cognomi = xmalloc(sizeof(Persona) * index);;

    printf("Inserire il cognome della persona: ");
    leggi(cognome);

    printf("\n");

    for(i = 0; i < index; i++) {
        found = cerca_persona_cognome(lista, cognome, index, &found);

        if(found != -1) {
            strcpy(nome, lista[found]->nome);

            elenco_con_cognomi[j] = xmalloc(sizeof(Persona));
            elenco_con_cognomi[j]->nome = xmalloc(sizeof(strlen(nome) + 1));
            elenco_con_cognomi[j]->cognome = xmalloc(sizeof(strlen(cognome) + 1));

            //*elenco_con_cognomi[i] = *lista[found];

            strcpy(elenco_con_cognomi[j]->nome, lista[found]->nome);
            strcpy(elenco_con_cognomi[j]->cognome, lista[found]->cognome);
            elenco_con_cognomi[j]->anni = lista[found]->anni;
            strcpy(elenco_con_cognomi[j]->codice_fiscale, lista[found]->codice_fiscale);

            j++;
            found++; // Incrementa found ogni volta che si trova un elemento per passarlo come argomento
            (*cognomi)++;
        }
    }

    if((*cognomi) > 0) {
        elenco_con_cognomi = realloc(elenco_con_cognomi, sizeof(Persona) * (*cognomi));

        if(!elenco_con_cognomi) {
            fprintf(stderr, "Error...byee <3\n");
            exit(-1);
        }

        return elenco_con_cognomi;
    }

    free(elenco_con_cognomi);
    return NULL;
}

void elimina_elenco(Persona **lista, int *index) {
    int i;

    for(i = 0; i < (*index); i++) {
       elimina_persona(lista[i]); 
    }

    *(index) = 0;
}