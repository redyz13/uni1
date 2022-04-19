#include <stdio.h>
#include "stack.h"

void inserisci(Stack s);

int main(void) {
    Stack s, rev, mer;

    s = newStack();
    
    inserisci(s);

    printStack(s);

    putchar('\n');

    rev = reverseStack(s);

    printStack(rev);

    mer = merge(s, rev);

    printf("\nMerge print\n");

    printStack(mer);

    mer = deleteItems(mer, 5);

    printf("\nAfter delete\n");

    printStack(mer);
    
    freeStack(mer);
    freeStack(s);
    freeStack(rev);

    return 0;
}

void inserisci(Stack s) {
    int x; 

    for(;;) {
        printf("Inserisci zoccola: ");
        scanf("%d", &x);

        if(x == -1) break;
        
        push(s, x);
    }
}
