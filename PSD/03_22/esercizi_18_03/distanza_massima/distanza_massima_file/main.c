#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

#define NPUNTI 30

int main(void) {
    int i, k;
    int n = 0, m = 0;
    float d = 0;
    float ascissa = 0, ordinata = 0, tmp;
    punto *p;
    FILE *fp;

    fp = fopen("input.txt", "r");

    if(!fp) {
        fprintf(stderr, "File non trovato...\n");
        return -1;
    }

    p = malloc(sizeof(punto) * NPUNTI);

    if(!p) return -1;

    // Lettura della distanza
    fscanf(fp, "%f", &d);

    while(fscanf(fp, "%f%f", &ascissa, &ordinata) == 2) {
        p[n++] = creapunto(ascissa, ordinata);
    }

    fclose(fp);

    p = realloc(p, sizeof(punto) * n);

    if(!p) return -1;

    // Calcola le distanze a coppie e controlla che siano minori di d
    for(i = 0; i < n; i++) {
        for(k = i + 1; k < n; k++) {
            tmp = distanza(p[i], p[k]);

            if(tmp < d) {
                m++;
            }
        }
    }

    printf("Le coppie di punti a distanza minore di %.2f sono %d\n", d, m);

    return 0;
}
