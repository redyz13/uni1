#include <stdio.h>
#include <string.h>

enum Strings {
    Ciao = 1,
    Troia = 2,
    Hello = 3
};

typedef struct {
    char *string;
    int value;
} StringsSwitch;

StringsSwitch lookuptable[] = {
    {"Ciao", Ciao}, {"Troia", Troia},
    {"Hello", Hello}
};

#define SIZE sizeof(lookuptable) / sizeof(StringsSwitch)

int string_compare(char *string) {
    int i = 0;
    char *tmp;

    while(i < SIZE) {
        tmp = lookuptable[i].string;
		
        if(!strcmp(tmp, string)) {
            return lookuptable[i].value;
        }

        i++;
    }

    return -1;
}

int main() {
    char string[] = "Troia";

    switch(string_compare(string)) {
        case Ciao: printf("Troia1"); break;
        case Troia: printf("Troia2"); break;
        case Hello: printf("Troia3"); break;
        default: printf("Vaffanculo");
    }

    return 0;
}
