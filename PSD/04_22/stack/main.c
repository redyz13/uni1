#include <stdio.h>
#include "stack.h"

int main(void) {
    Stack s;

    s = newStack();

    push(s, 10);
    push(s, 20);
    push(s, 30);

    pop(s);

    int x = top(s);

    printf("%d", x);

    freeStack(s);

    return 0;
}
