#include <stdio.h>
#include <string.h>
#define STRLEN 50

void read(char str[]);
void reverse(char str[]);

int main() {
    char str[STRLEN+1];

    read(str);
    reverse(str);

    printf("\nReversed string: %s", str);
}

void read(char str[]) {
    int term;

    printf("Insert a string: ");
    fgets(str, STRLEN, stdin);

    term = strlen(str);

    str[term-1] = '\0';
}

void reverse(char str[]) {
    int i, len;
    char temp;

    len = strlen(str);

    for(i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
