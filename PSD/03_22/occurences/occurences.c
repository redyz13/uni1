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

int confronta_lettere(const char *sub_string, const char *string);
int conta_occorenze(FILE *fp, const char *s);

int main(int argc, char **argv) {
    FILE *fp;
    int occorenze;

    if(argc < 3) {
        printf("Utilizzo: <%s stringa nomefile>\n", argv[0]);
    }
    else {
        fp = fopen(argv[2], "r");

        if(!fp) {
            fprintf(stderr, "File non trovato...\n");
            return -1;
        }

        occorenze = conta_occorenze(fp, argv[1]);

        fclose(fp);

        printf("La parola è presente %d volte/a "
               "all'interno del file\n", occorenze);
    }

    return 0;
}

int confronta_lettere(const char *sub_string, const char *string) {
    int s_len, sub_len;
    int i, j;

    sub_len = strlen(sub_string);
    s_len = strlen(string);

    for(i = 0; i <= s_len - sub_len; i++) {
        for(j = 0; j < sub_len; j++) {
            if(sub_string[j] != string[i+j]) {
                break;
            }
        }

        if(j == sub_len) {
            return 1;
        }
    }

    return 0; 
}

int conta_occorenze(FILE *fp, const char *s) {
    int i, count = 0, lun = 0;

    lun = strlen(s);

    char tmp[lun+1];

    while(!feof(fp)) {
        for(i = 0; i < lun; i++) {
            tmp[i] = fgetc(fp);
        }

        tmp[i] = '\0';

        printf("%s\n", tmp);

        if(confronta_lettere(s, tmp)) {
            count++;
        }

        fseek(fp, lun - 1, SEEK_CUR);
    }

    return count;
}
