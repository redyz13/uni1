#include <stdio.h>
#include <string.h>
#define STRLEN 30

void leggi(char []);
void minus_maius(char a[]);

int main() {
    char str[STRLEN+1];

    leggi(str);
    minus_maius(str);

    printf("\nStringa con lettere e maiuscole invertite:\n\n%s", str);

}

void leggi(char str[]) {
    printf("Inserisci una stringa: ");
    fgets(str, STRLEN, stdin);

    str[strlen(str)-1] = '\0';
}

void minus_maius(char a[]) {
	int i, len;

	len = strlen(a);

	for(i = 0; i < len; i++) {
		if(a[i] >= 'A' && a[i] <= 'Z') {
			a[i] += 'a' - 'A';
		}
		else if(a[i] >= 'a' && a[i] <= 'z') {
			a[i] -= 'a' - 'A';
		}
	}
}
