#ifndef __PERSONA_H_
#define __PERSONA_H_ 

#include <stdio.h>

struct {
    char *nome;
    char *cognome;
    int anni;
    char codice_fiscale[16+1];
} typedef Persona;

void leggi(char *str);

void *xmalloc(size_t bytes);

void elimina_persona(Persona *p);

void elenca_persone(Persona **lista, int index);

void print_persona(Persona *p);

Persona *inserisci_persona(int *index);

// Cerca una persona in base al cf (restituisce il primo indice trovato) 
int cerca_cf(Persona **lista, int index);

// Cerca una persona in base al nome e cognome (restituisce il primo indice trovato) 
int cerca_nm(Persona **lista, int index);

int check_codice(char *str);

Persona **crea_elenco(Persona **lista, int index, int *cognomi);

// Cerca una persona passando il cf come parametro
int cerca_persona(Persona **lista, char *codice_fiscale, int index);

/* Cerca le persone in base al cognome, current_index è l'indice da cui far partire la ricerca
*  mentre index l'indice totale dell'array
*  per il corretto funzionamento incrementare di 1 current_index (fuori dalla funzione) per ogni ricerca
*  avvenuta correttamente 
*/
int cerca_persona_cognome(Persona **lista, char *cognome, int index, int *current_index);

void elimina_elenco(Persona **lista, int *index);

#endif