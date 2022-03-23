#include <stdio.h>
#include <stdlib.h>
#include "file.h"

#define NPUNTI 30

FILE *apri_file(char *file_name, char *mode) {
    FILE *fp;

    fp = fopen(file_name, mode);

    if(!fp) {
        fprintf(stderr, "File non trovato...\n");
        exit(-1);
    }

    return fp;
}

punto *finput_punto(char *file_name, int *npunti) {
    FILE *fp;
    punto *p;
    float ascissa, ordinata;
    *npunti = 0;

    fp = apri_file(file_name, "r");

    p = malloc(sizeof(punto) * NPUNTI);

    if(!p) {
        exit(-1);
    }

    while(fscanf(fp, "%f%f", &ascissa, &ordinata) == 2) {
        p[*npunti] = creapunto(ascissa, ordinata);
        (*npunti)++;
    }

    p = realloc(p, sizeof(punto) * (*npunti));

    // Stellina alzheimer, è importante chiudere i file prima di usire
    // dal programma
    fclose(fp);

    if(!p) {
        exit(-1);
    }

    return p;
}

void foutput_punto(char *file_name, float m) {
    FILE *fp;

    fp = apri_file(file_name, "w");

    fprintf(fp, "%f", m);

    fclose(fp);
}

float fread_oracle(char *oracle_fname) {
    FILE *fp;
    float m;

    fp = apri_file(oracle_fname, "r");

    fscanf(fp, "%f", &m);

    fclose(fp);

    return m;
}
