#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lshift(char *s, int j);
void removeSpaces(char *s);
int palindroma(char *s);

int main(void) {
    char str[] = "o s s o";

    removeSpaces(str);

    printf("La stringa %s palindroma\n",
          palindroma(str) ? "è" : "non è");

    return 0;
}

/*
    Postcondizioni:
        1. La stringa viene persa
*/
int palindroma(char *s) {
    if (s[0] != s[strlen(s) - 1])
        return 0;

    s++;
    s[strlen(s) - 1] = '\0';

    if (strlen(s) <= 1)
        return 1;

    palindroma(s);
}

void lshift(char *s, int j) {
    int i;

    for (i = j; i < strlen(s) - 1; i++)
        s[i] = s[i+1];

    s[i] = '\0';
}

void removeSpaces(char *s) {
    for (int i = 0; i < strlen(s) - 1; i++)
        if (isspace(s[i]))
            lshift(s, i);
}
