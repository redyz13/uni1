#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct Punto {
    float ascissa;
    float ordinata;
};

Punto creaPunto(float x, float y) {
    Punto p; 
    
    p = malloc(sizeof(*p));
    if(!p) return NULL;

    p->ascissa = x;
    p->ordinata = y;
    
    return p;
}

float getAscissa(Punto p) {
    return p->ascissa;
}

float getOrdinata(Punto p) {
    return p->ordinata;
}

int isEqual(Punto p1, Punto p2) {
    return (p1->ascissa == p2->ascissa && p1->ordinata == p2->ordinata); 
}

float distanza(Punto p1, Punto p2) {
    if(p1 == NULLITEM || p2 == NULLITEM) return 0;

    float dx = p1->ascissa - p2->ascissa; 
	float dy = p1->ordinata - p2->ordinata; 
	float d = sqrt(dx * dx + dy * dy); 

	return d;
}

void printItem(Punto p){
    printf("\nAscissa: %.2f\n", p->ascissa);
    printf("Ordinata: %.2f\n", p->ordinata);
}

void freePunto(Punto p) {
    free(p);
}
