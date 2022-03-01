#ifndef __EBREO_H_
#define __EBREO_H_ 

typedef struct {
    char *nome;
    char *cognome;
    int anni;
    int id;
} ebreo;

ebreo *build_ebreo(const char nome[], const char cognome[], int anni, int id);

void ebrei_default(ebreo *ebreo[], int *index);

void leggi_stringa(char str[]);

ebreo *alloca_ebreo(ebreo *e);

ebreo *censisci_ebrei(ebreo *ebreo);

void elenca_ebrei(ebreo *ebreo[], int index);

void print_ebreo(ebreo *ebreo); 

int metti_nel_forno(ebreo *ebreo[], int *index);

int cerca_ebreo(ebreo *ebreo[], int index); 

#endif