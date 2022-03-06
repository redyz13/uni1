/* Creare una funzione char *merge(char *, char *) che prende in
 * input il nome e il cognome e produca una nuova stringa che è il
 * risultato della concatenazione delle due date in input
 *
 * Una funzione char *incastona(char *, char *) che produce una nuova
 * stringa secondo la seguente regola: la più piccola delle due va
 * incastonata nella più lunga sostituendo i caratteri di questa ultima
 * Esempio: a = "fabio" b = "narducci" restituirà in output la stringa
 * c = "nfabioci" (nota. quando la stringa più lunga ha un numero pari di
 * caratteri, la stringa più corta viene incastonata al centro a meno di un
 * carattere a sx o dx)
 *
 * Una funzione void ordina(char *) che ordini i caratteri del nome e del
 * cognome con un algoritmo a scelta tra InsertionSort o BubbleSort
 *
 * Note:
 *
 * Dal momento che non è nota a priori la dimensione dell'array, è opportuno
 * gestire l'allocazione dell'array in maniera dinamica
 *
 * Convertire e gestire opportunatamente i due diversi tipi di dato char e
 * int e relativi puntatori
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getchar() getc(stdin)

char *leggi_stringa(int buff); 
char *merge(const char *s1, const char *s2);

int main(void) {
    char *nome, *cognome;
    char *concat;

    printf("Inserire il proprio nome: ");
    nome = leggi_stringa(25);

    printf("Inserire il proprio cognome: ");
    cognome = leggi_stringa(25);

    printf("\nNome inserito: %s", nome);
    printf("\nCognome inserito: %s", cognome);

    concat = merge(nome, cognome);

    printf("\nConcatenazione di nome e cognome: %s", concat);

    return 0;
}

char *leggi_stringa(int buff) {
    char *s;
    char tmp[buff+1];
    int lun;
    int ch, i = 0;

    while((ch = getchar()) != '\n') {
        if(i < buff) {
            tmp[i++] = ch;
        }
    }

    tmp[i] = '\0';

    lun = strlen(tmp);

    s = malloc(lun + 1);

    if(!s) {
        return NULL;
    }

    strcpy(s, tmp);

    return s;
}

char *merge(const char *s1, const char *s2) {
    char *p;
    char *pi;

    // Alloco una dimensione sufficiente per concatenare le stringhe
    p = malloc(strlen(s1) + strlen(s2) + 1);

    // Utilizzo un altro puntatore per mantenere intatto l'indirizzo di base
    pi = p;

    strcpy(p, s1);

    // Scorro la stringa fino a trovare il carattere terminatore
    while(*pi)
        pi++;

    /* Inizio a copiare i caratteri dal terminatore della prima stringa
    *  fino all'ultimo carattere della seconda
    *  I due puntatori vengono incrementati dopo l'assegnamento e la condizione
    *  del while è il risultato dell'assegnamento stesso, che sarà '\0 (quindi 0)
    *  quando avrà trovato il terminatore della seconda stringa, uscendo dal while
    */
    while((*pi++ = *s2++))
        ;

    return p;
}
