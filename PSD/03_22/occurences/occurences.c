/* Scrivere un programma occurences che riceva dalla linea di comando
 * una stringa str e il nome di un file di testo, stampando a video
 * il numero di volte che la sequenza di caratteri str compare nel file
 *
 * Modificare il programma in modo che accetti, oltre al nome del file,
 * anche un secondo parametro mode, che può assumere due valori:
 * "o" per contare il numero di occorenze di una stringa str che verrà
 * inserita come terzo parametro, oppure "s" per ordinare le stringhe
 * presenti nel file in ordine lessicografico
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFREAD 50

int confronta_stringhe(const char *sub_string, const char *string);
int conta_occorenze(FILE *fp, const char *s);
char *leggi_caratteri(FILE *fp); 
void bubble_sort(char *s1);
void ordina_stringhe(FILE *fp);

int main(int argc, char **argv) {
    FILE *fp;
    int occorenze;

    if(argc < 3) {
        printf("Utilizzo: <%s nomefile mode(o/s) stringa(per mode s)>\n", argv[0]);
    }
    else {
        fp = fopen(argv[1], "r+");

        if(!fp) {
            fprintf(stderr, "File non trovato...\n");
            return -1;
        }

        if(!strcmp(argv[2], "o")) {
            occorenze = conta_occorenze(fp, argv[3]);

            fclose(fp);

            printf("La stringa è presente %d volte/a "
                   "all'interno del file\n", occorenze);
        }
        else if(!strcmp(argv[2], "s")) {
            ordina_stringhe(fp);
            printf("Stringhe del file ordinate\n");

            fclose(fp);
        }
    }

    return 0;
}

int confronta_stringhe(const char *sub_string, const char *string) {
    while(*string) {
        if(*sub_string++ != *string++) {
            return 0;
        }
    }

    return 1;
}

int conta_occorenze(FILE *fp, const char *s) {
    int i, count = 0, lun = 0;
    int ch;

    lun = strlen(s);

    char tmp[lun+1];

    do {
        for(i = 0; i < lun; i++) {
            ch = fgetc(fp);
            tmp[i] = ch;
        }

        tmp[i] = '\0';

        if(confronta_stringhe(s, tmp)) {
            count++;
        }

        fseek(fp, (-lun + 1), SEEK_CUR);
    } while(ch != EOF);

    return count;
}

char *leggi_caratteri(FILE *fp) {
    int ch;
    int i = 0, lun;
    char tmp[BUFREAD+1], *s;

    while(1) {
        ch = fgetc(fp);

        if(ch != ' ' && ch != '\n' && ch != EOF) {
            tmp[i++] = ch;
        }
        else {
            break;
        }
    }

    tmp[i] = '\0';

    lun = strlen(tmp);

    s = malloc(lun + 1);

    if(!s) {
        exit(-1);
    }

    strcpy(s, tmp);

    return s;
}

void bubble_sort(char *s1) {
    int i, j, lenght;
    int tmp;

    lenght = strlen(s1);

    for(i = 0; i < lenght; i++) {
        for(j = 0; j < (lenght - 1 - i); j++) {
            if(s1[j] > s1[j+1]) {
                tmp = s1[j];
                s1[j] = s1[j+1];
                s1[j+1] = tmp;
            }
        }
    }
}

void ordina_stringhe(FILE *fp) {
    char *s;
    int ch;

    while((ch = fgetc(fp)) != EOF) {
        if(ch == EOF) {
            return;
        }

        // Spostare il cursore di una lettera prima
        // per via della condizione nel ciclo while
        fseek(fp, -1, SEEK_CUR);

        s = leggi_caratteri(fp);
        bubble_sort(s);

        // Sposta il cursore della lunghezza di una parola
        // (+1 per lo spazio) indietro
        fseek(fp,  (-strlen(s)) - 1, SEEK_CUR);

        fprintf(fp, "%s", s);

        // Sposta il cursore avanti di uno per lo spazio
        fseek(fp, 1, SEEK_CUR);
        free(s);
    }
}
