/*
 * Legge due stringhe e verifica se la prima
 * stringa è postfissa della seconda
*/

#include <stdio.h>
#include <string.h>
#define STRLEN 30

int main() {
    char str1[STRLEN];
    char str2[STRLEN];
    int str1len, str2len, i, counter = 0;
    int templen1, templen2;

    /*
     * Utilizzo di fgets per memorizzare anche
     * stringhe contenenti spazi 
     * fgets prevede sempre di inserire nella
     * stringa uno \n prima del carattere nullo \0
    */

    printf("Insert the first string: ");
    fgets(str1, STRLEN, stdin);
    printf("Insert the second string: ");
    fgets(str2, STRLEN, stdin);

    str1len = strlen(str1);
    str2len = strlen(str2);

    /*
     * Dopo aver memorizzato il numero di caratteri delle due
     * stringhe, si sottrare -1 per escludere
     * il carattere \n generato da fgets
    */
    
    templen1 = str1len - 1; 
    templen2 = str2len - 1; 

    /*
     * Nei cicli dovrò ancora una volta sottrarre -1
     * alle lunghezze delle stringhe poiché sto utilizzando 
     * quel valore per indicare le celle di un array
    */
    for(i = templen2 - 1; i > 0; i--) {
        /*
         * Verifico che gli ultimi caratteri della seconda
         * stringa siano uguali a quelli della prima e memorizzo
         * in un contatore che dovrà poi essere uguale alla
         * lunghezza della prima stringa
        */
        if(str2[templen2-1] == str1[templen1-1]) {
            counter++;
        }

        templen1--;
        templen2--;
    }


    if(counter == str1len - 1) // str1len -1 per escludere \n
        printf("\nLa prima stringa è postfissa della seconda\n");
    else
        printf("\nLa prima stringa non è postfissa della seconda\n");

    return 0;
}
