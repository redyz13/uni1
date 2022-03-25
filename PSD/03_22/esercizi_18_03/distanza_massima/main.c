#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

void distanza_massima(punto *p, int n);

int main(int argc, char *argv[]) {
    int i, j;
    int n = 0, m = 0;
    float d = 0;
    float ascissa = 0, ordinata = 0;
    punto *p;

    // Carica tutto l'input: coppie e distanza
    if(argc < 4 || (argc % 2 != 0)) {
        fprintf(stderr, "formato: <%s, distanza, coppie...>\n", argv[0]);
        return -1;
    }

    n = (argc - 2) / 2;

    p = malloc(sizeof(punto) * n);

    if(!p) return -1;

    d = atof(argv[1]);

    j = 0;

    for(i = 2; i < argc; i += 2) {
        ascissa = atof(argv[i]);
        ordinata = atof(argv[i+1]);

        p[j] = creapunto(ascissa, ordinata);

        stampa(p[j]);

        j++;
    }

    distanza_massima(p, n);

    return 0;
}

void distanza_massima(punto *p, int n) {
    int i, q;
    float tmp, max = 0;
    float ascissa1, ordinata1, ascissa2, ordinata2;

    for(i = 0; i < n; i++){
        for(q = i + 1; q < n; q++){
            tmp = distanza(p[i], p[q]);

            if(tmp > max) {
                max = tmp;

                ascissa1 = ascissa(p[i]);
                ascissa2 = ascissa(p[q]);

                ordinata1 = ordinata(p[i]);
                ordinata2 = ordinata(p[q]);
            }
        }
    }

    printf("I punti a distanza massima sono: [%.2f,%.2f] ", ascissa1, ordinata1);
    printf("[%.2f ,%.2f]\n", ascissa2, ordinata2); 
}
