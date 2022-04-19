#include "item.h"

typedef struct Stack *Stack;

Stack newStack(void);

int isEmpty(Stack s);

int push(Stack s, Item it);

int pop(Stack s);

Item top(Stack s);

Stack reverseStack(Stack s);

void printStack(Stack s);

void freeStack(Stack s); 

Stack merge(Stack s1, Stack s2);

Stack deleteItems(Stack s, Item it);
