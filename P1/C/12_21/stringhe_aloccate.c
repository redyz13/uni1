#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRLEN 80

void leggi(char str[]);
char *leggi_stringa(int max_lun); 

int main() {
    char *str;

    str = leggi_stringa(STRLEN);

    printf("%s\n", str);

    return 0;
}

void leggi(char str[]) {
    printf("Inserisci una stringa: ");
    fgets(str, STRLEN, stdin);

    str[strlen(str)-1] = '\0';
}

// Di Tucci
/*char *leggi_stringa(int max_lun) {
    char *s, *s1;
    int lun;

    s = (char *) malloc(max_lun + 1);

    if(!s) return NULL;

    leggi(s);
    lun = strlen(s);

    s1 = malloc(lun + 1);

    if(!s1) return NULL;

    strncpy(s1, s, lun);

    free(s);

    return s1;
}*/

// Meglio di Tucci
char *leggi_stringa(int max_lun) {
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
