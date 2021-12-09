#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LUN 20 

typedef struct {
    char *nome;
    char *cognome;
    char codice_fiscale[16+1];
} persona;

void leggi_stringa(char str[]); 
void *xmalloc(size_t size);
persona *inserisci_persona(persona *persona);
int check_codice(char str[]);

int main() {
    persona *p = NULL; 

    p = inserisci_persona(p);

    if(check_codice(p->codice_fiscale))
        printf("[Codice fiscale valido]\n");
    else
        printf("[Codice fiscale non valido]\n");

    return 0;
}

void leggi_stringa(char str[]) {
    int n;

    fgets(str, MAX_LUN+2, stdin);

    n = strlen(str);

    if(str[n-1] == '\n') str[n-1] = '\0';
}

void *xmalloc(size_t size) {
    void *p;

    p = malloc(size);

    if(!p) return NULL;

    return p;
}

persona *inserisci_persona(persona *persona) {
    persona = xmalloc(sizeof(persona));

    char nome[MAX_LUN+1], cognome[MAX_LUN+1];
    char codice_fiscale[16+1];

    printf("Inserire il nome: "); 
    leggi_stringa(nome);
    printf("Inserire il cognome: ");
    leggi_stringa(cognome);
    printf("Inserire il codice fiscale: ");
    leggi_stringa(codice_fiscale);
    printf("\n");

    persona->nome = xmalloc(strlen(nome) + 1);
    strcpy(persona->nome, nome);

    persona->cognome= xmalloc(strlen(cognome) + 1);
    strcpy(persona->cognome, cognome);

    strcpy(persona->codice_fiscale, codice_fiscale);

    return persona;
}

int check_codice(char str[]) {
    // Questo elemento piace al prof. Distasi <3
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
