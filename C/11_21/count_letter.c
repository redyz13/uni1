#include <stdio.h>
#include <string.h>
#define STRLEN 50

void leggi(char []);
int count_letter(char str[], char l);

int main() {
    char str[STRLEN+1], l;
    int k;

    leggi(str);
    
    printf("Inserisci il carattere per il quale contare le istanze: ");
    scanf("%c", &l);

    k = count_letter(str, l);

    printf("\nLa lettera %c è presente %d volte", l, k);
}

void leggi(char str[]) {
    int term;

    printf("Inserisci una stringa: ");
    fgets(str, STRLEN, stdin);

    term = strlen(str);

    str[term-1] = '\0';
}

int count_letter(char str[], char l) {
    int i, k = 0;
    int len;

    len = strlen(str);

    // Controllo se è una lettera dell'alfabeto'
    if((l >= 'A' && l <= 'Z') || (l >= 'a'&& l <= 'z')) {
        for(i = 0; i < len; i++) {
            if(l == str[i] || l == str[i] + 'a' - 'A'
               || l == str[i] - 'a' - 'A') {
                k++;
            }
        }

        return k;
    }
    else {
        return 0;;
    }
}
