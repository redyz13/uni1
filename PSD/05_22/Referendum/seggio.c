#include <stdio.h>
#include <stdlib.h>
#include "seggio.h"

struct Scheda {
	int id_scheda;
	int aventi_diritto_voto;
	int votanti;
	int voti_nulli;
	int voti_si;
	int voti_no;
};

struct Seggio {
	int id_seggio;
	Scheda scheda;
};

void printSeggio(Seggio seggio) {
	if (seggio == NULLITEM) return;
	
	printf("ID seggio: %d\n", seggio->id_seggio);
	printf("ID scheda seggio: %d\n", seggio->scheda->id_scheda);
}

Scheda getScheda(Seggio seggio) {
	if (seggio == NULLITEM) return NULLITEM;
	
	return seggio->scheda;
}

int getIdScheda(Scheda scheda) {
	if (scheda == NULLITEM) return -1;
	
	return scheda->id_scheda;
}

int getIdSeggio(Seggio seggio) {
	if (seggio == NULLITEM) return -1;
	
	return seggio->id_seggio;
}

Scheda creaScheda(int id_scheda, int aventi_diritto_voto, int votanti,
				  int voti_nulli, int voti_si, int voti_no)
{
	Scheda s;
	
	s = malloc(sizeof(struct Scheda));
	if (s == NULL) return NULL;
	
	s->id_scheda = id_scheda;
	s->aventi_diritto_voto = aventi_diritto_voto;
	s->votanti = votanti;
	s->voti_nulli = voti_nulli;
	s->voti_si = voti_si;
	s->voti_no = voti_no;
	
	return s;
}

Seggio creaSeggio(int id_seggio, Scheda scheda) {
	if (scheda == NULL) return NULL;
	Seggio s;
	
	s = malloc(sizeof(struct Seggio));
	if (s == NULL) return NULL;
	
	s->id_seggio = id_seggio;
	s->scheda = scheda;
	
	return s;
}