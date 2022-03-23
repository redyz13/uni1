#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct miopunto {
    float ascissa;
    float ordinata;
};
      
punto creapunto(float x, float y) {
    punto p; 
    
    p = malloc(sizeof(*p));
    if(!p) return NULL;

    p->ascissa = x;
    p->ordinata = y;
    
    return p;
}

float ascissa(punto p) {
    return p->ascissa;
}

float ordinata(punto p) {
    return p->ordinata;
}

float distanza(punto p1, punto p2) {
    float dx = p1->ascissa - p2->ordinata; 
	float dy = p1->ascissa - p2->ordinata; 
	float d = sqrt(dx*dx + dy*dy); 

	return d;
}

void stampa (punto p) {
    printf("Ascissa: %.2f\n", p->ascissa);
    printf("Ordinata: %.2f\n\n", p->ordinata);
}

int calcolo_distanze(punto *p, int n, int d) {
    float tmp;
    int i, k;
    int m = 0;

    for(i = 0; i < n; i++) {
        for(k = i + 1; k < n; k++) {
            tmp = distanza(p[i], p[k]);

            if(tmp < d) {
                m++;
            }
        }
    }

    return m;
}
