/*
 * Legge due stringhe e verifica se la prima
 * stringa è postfissa della seconda
*/

#include <stdio.h>
#include <string.h>
#define STRLEN 30

void leggi(char str[]);

int main() {
    char str1[STRLEN+1];
    char str2[STRLEN+1];
    int str1len, str2len, i, counter = 0;

    leggi(str1);
    leggi(str2);

    str1len = strlen(str1);
    str2len = strlen(str2);

    for(i = str2len - 1; i > 0; i--) {
        /*
         * Verifico che gli ultimi caratteri della seconda
         * stringa siano uguali a quelli della prima e memorizzo
         * in un contatore che dovrà poi essere uguale alla
         * lunghezza della prima stringa
        */
        if(str2[str2len-1] == str1[str1len-1]) {
            counter++;
        }

        /*
         * Ferma il ciclo una volta controllati tutti i caratteri
         * di str1
        */ 
        if(str1len == 0)
            break;

        str1len--;
        str2len--;
    }


    if(counter == strlen(str1))
        printf("\nLa prima stringa è postfissa della seconda\n");
    else
        printf("\nLa prima stringa non è postfissa della seconda\n");

    return 0;
}

void leggi(char str[]) {
    int term;

    printf("Inserisci una stringa: ");
    fgets(str, STRLEN, stdin);

    term = strlen(str);

    // Elimino il carattere \n aggiunto dalla fgets
    str[term-1] = '\0';
}
