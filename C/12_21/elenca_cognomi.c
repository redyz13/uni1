#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LUN 40
#define NUM_STR 3

void leggi(char str[]);
char *alloca_stringa(int max_lun);
void inserisci_coppie(char *el[][2]);
int name_compare(char str[], char str2[]);
void stampa_associati(char *el[][2], char nome[]);

int main() {
    char *el[NUM_STR][2];
    char nome[MAX_LUN+1];

    inserisci_coppie(el);

    printf("Inserire un nome: ");
    leggi(nome);
    printf("\n");
    printf("Cognomi associati:\n");

    stampa_associati(el, nome);

    printf("\n");

    return 0;
}

void leggi(char str[]) {
    int n;
    
    fgets(str, MAX_LUN+1, stdin);

    n = strlen(str);

    if(str[n-1] == '\n') str[n-1] = '\0';
}

char *alloca_stringa(int max_lun) {
    char *s;
    int lun;

    s = (char *) malloc(max_lun + 1);

    if(!s) return NULL;

    leggi(s);
    lun = strlen(s);

    s = realloc(s, lun + 1);

    if(!s) return NULL;

    return s;
}

void inserisci_coppie(char *el[][2]) {
    int i;

    for(i = 0; i < NUM_STR; i++) {
        printf("Inserisci nome %d: ", i+1);
        el[i][0] = alloca_stringa(MAX_LUN+1);
        printf("Inserisci cognome %d: ", i+1);
        el[i][1] = alloca_stringa(MAX_LUN+1);
        printf("\n");
    }
}

int name_compare(char str[], char str2[]) {
    if(!strcmp(str, str2))
        return 1;
    else
        return 0;
}

void stampa_associati(char *el[][2], char nome[]) {
    int i;

    for(i = 0; i < NUM_STR; i++) {
        if(name_compare(el[i][0], nome)) {
            printf("\n%s", el[i][1]);
        }
    }
}
