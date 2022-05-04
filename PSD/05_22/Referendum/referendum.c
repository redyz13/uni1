#include <stdio.h>
#include <stdlib.h>
#include "referendum.h"

#define MAXSEGGI 20

struct Referendum {
    struct Referendum *next;
    Seggio seggio;
};

Referendum creaRef(void) {
    return NULL;
}

int isEmpty(Referendum r) {
    return r == NULL;
}

static int isIdPresent(Referendum r, Scheda scheda) {
    Scheda tmp_scheda;
    int tmp_id;
    int id_scheda = getIdScheda(scheda);
    
    while (!isEmpty(r)) {
        tmp_scheda = getScheda(r->seggio);
        tmp_id = getIdScheda(tmp_scheda);
        
        if (id_scheda == tmp_id)
            return 1;
        
        r = r->next;
    }
    
    return 0;
}

Referendum insertSeggio(Referendum r, Seggio seggio) {
    if (seggio == NULLITEM) return r;
    
    // Controlla se la lista dei seggi è piena
    if (completeRef(r)) return r;
    
    // L'id dei seggi deve essere compreso tra 1 e MAXSEGGI
    if (getIdSeggio(seggio) > MAXSEGGI || getIdSeggio(seggio) < 1)
        return r;
    
    // L'id della scheda del seggio deve essere univoco
    if (isIdPresent(r, getScheda(seggio)))
        return r;
    
    Referendum new;
    
    new = malloc(sizeof(struct Referendum));
    if (new == NULL) return r;
    
    new->seggio = seggio;
    
    if (r == NULL) {
        new->next = NULL;
        r = new;
        return new;
    }
    
    new->next = r;
    r = new;
    
    return new;
}

void printSeggi(Referendum r) {
    int i = 0;
    
    while (r != NULL) {
        printf("--- Seggio %d ---\n", i++);
        printSeggio(r->seggio);
        putchar('\n');
        r = r->next;
    }
}

int completeRef(Referendum r) {
    int i = 0;
    
    while (r != NULL) {
        i++;
        r = r->next;
    }
    
    return i >= MAXSEGGI;
}

void stampaReport(Referendum r) {
    if (isEmpty(r)) return;

    Seggio seggio;
    Scheda scheda;

    int tot_votanti = 0, tot_voti_nulli = 0;
    int tot_voti_si = 0, tot_voti_no = 0;

    printf("\n--- REPORT ---\n");

    while (!isEmpty(r)) {
        seggio = r->seggio;
        scheda = getScheda(seggio);

        tot_votanti += getVotanti(scheda);
        tot_voti_nulli += getVotiNulli(scheda);
        tot_voti_si += getVotiSi(scheda);
        tot_voti_no += getVotiNo(scheda);

        r = r->next;
    }

    printf("\nTotale votanti: %d", tot_votanti);
    printf("\nTotale voti nulli: %d", tot_voti_nulli);
    printf("\nTotale voti sì: %d", tot_voti_si);
    printf("\nTotale voti no: %d\n", tot_voti_no);
}

int noSiRef(Referendum r) {
    if (isEmpty(r)) return 0;

    Seggio seggio;
    Scheda scheda;

    int tot_voti_si = 0, tot_voti_no = 0;

    while (!isEmpty(r)) {
        seggio = r->seggio;
        scheda = getScheda(seggio);

        tot_voti_si += getVotiSi(scheda);
        tot_voti_no += getVotiNo(scheda);
    
        r = r->next;
    }

    return tot_voti_si > tot_voti_no;
}