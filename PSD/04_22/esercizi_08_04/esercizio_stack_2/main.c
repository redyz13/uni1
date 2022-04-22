#include <stdio.h>
#include "stack.h"

void inserisci(Stack s);
Stack clone(Stack s); 
Stack inverti(Stack s);
Stack merge(Stack s1, Stack s2);
void removeItems(Stack s, Item it);

int main(void) {
    Stack s, rev, mer; 

    s = newStack();
    
    inserisci(s);

    putchar('\n');

    printStack(s);

    putchar('\n');

    rev = inverti(s);   

    printStack(rev);

    mer = merge(s, rev);   

    putchar('\n');

    printStack(mer);

    putchar('\n');

    removeItems(mer, 5);

    printStack(mer);

    freeStack(s);
    freeStack(rev);
    freeStack(mer);
    
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

Stack merge(Stack s1, Stack s2) {
    Stack mer, tmp1, tmp2;

    mer = newStack();
    
    tmp1 = clone(s1);
    tmp2 = clone(s2);

    while(!isEmpty(tmp1)) {
        push(mer, top(tmp1));
        pop(tmp1);
    }

    while(!isEmpty(tmp2)) {
        push(mer, top(tmp2));
        pop(tmp2);
    }

    Stack t = mer;
    mer = inverti(mer);
    freeStack(t);

    freeStack(tmp1);
    freeStack(tmp2);

    return mer;
}

Stack clone(Stack s) {
    Stack clone, tmp; 
    
    tmp = newStack();
    clone = newStack();

    while(!isEmpty(s)){
        push(tmp, top(s));
        pop(s);
    }

    while(!isEmpty(tmp)) {
        push(clone, top(tmp));
        push(s, top(tmp));
        pop(tmp);
    }

    freeStack(tmp);
    
    return clone;
} 

Stack inverti(Stack s) {
    Stack rev, tmp;

    rev = newStack();
    tmp = clone(s);

    while(!isEmpty(tmp)) {
        push(rev, top(tmp));
        pop(tmp);
    }

    freeStack(tmp);

    return rev;
}

void removeItems(Stack s, Item it) {
    Stack new;

    new = newStack();

    while(!isEmpty(s)) {
        if(!isEqual(it, top(s))) {
            push(new, top(s));
        }
        
        pop(s);
    }

    while(!isEmpty(new)) {
        push(s, top(new));
        pop(new);
    }

    freeStack(new);
}
