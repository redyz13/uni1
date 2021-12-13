#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLUN 30

int primadi(char *fname, char *spartiacque, char *a[], int sizea);
void leggi(char *str);
void *xmalloc(size_t size);
void riempi_stringhe(char *a[], int sizea); 
int get_dim(int min, int max);

int main() {
    char filename[MAXLUN+1];
    char spartiacque[MAXLUN+1];
    int sizea;

    printf("Inserire il nome del file: ");
    leggi(filename);

    printf("Inserire la stringa spartiacque: ");
    leggi(spartiacque);

    printf("\nQuante stringhe vuoi inserire? (max 10)");
    sizea = get_dim(1, 10);

    char *a[sizea];

    while(getchar() != '\n'); // clean buffer

    riempi_stringhe(a, sizea);
    primadi(filename, spartiacque, a, sizea);

    printf("\nRisulsato salvato nel file <%s>\n", filename);

    return 0;
}

void leggi(char *str) {
    int lun;

    fgets(str, MAXLUN+2, stdin);

    lun = strlen(str);

    if(str[lun-1] == '\n')
        str[lun-1] = '\0';
}

void *xmalloc(size_t size) {
    void *p;

    p = malloc(size);

    if(p == NULL) {
        fprintf(stderr, "Errore\n");
        exit(-1);
    }

    return p;
}

int get_dim(int min, int max) {
    int x;

    do {
        printf("\nInserire un numero intero positivo: ");
        scanf("%d", &x);
    } while(x < min || x > max);

    return x;
}

void riempi_stringhe(char *a[], int sizea) {
    int i, lun;
    char tmp[MAXLUN+1];

    printf("\n");

    for(i = 0; i < sizea; i++) {
        printf("Inserire la stringa %d: ", i + 1);
        leggi(tmp);
        lun = strlen(tmp);
        a[i] = xmalloc(lun+1);
        strcpy(a[i], tmp);
    }
}

int primadi(char *fname, char *spartiacque, char *a[], int sizea) {
    FILE *fp;
    int i, count = 1;

    fp = fopen(fname, "w");

    if(fp == NULL) {
        fprintf(stderr, "Errore nell'apertura del file: <%s>\n", fname);
        exit(-1);
    }

    for(i = 0; i < sizea; i++) {
        if((strcmp(a[i], spartiacque)) < 0) {
            fprintf(fp, "%s\n", a[i]);
            count++;
        }
    }

    fprintf(fp, "END\n");
    fclose(fp);

    return count;
}