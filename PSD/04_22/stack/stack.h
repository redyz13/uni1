#include "item.h"

typedef struct Stack *Stack;

Stack newStack(void);

int isEmpty(Stack s);

int push(Stack s, Item it);

int pop(Stack s);

Item top(Stack s);

void freeStack(Stack s);
