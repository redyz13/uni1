#include <stdio.h>
#include <stdlib.h>
#include "referendum.h"

#define MAXSEGGI 50

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
	
	Scheda scheda = getScheda(seggio); 
	
	// L'id dei seggi deve essere compreso tra 0 e MAXSEGGI
	if (getIdSeggio(seggio) > MAXSEGGI || getIdSeggio(seggio) < 0)
		return r;
	
	// L'id della scheda del seggio deve essere univoco
	if (isIdPresent(r, scheda))
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

void stampa(Referendum r) {
	int i = 0;
	
	while(r != NULL) {
		printf("--- Seggio %d ---\n", i++);
		printSeggio(r->seggio);
		putchar('\n');
		r = r->next;
	}
}