#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack {
    struct Node* head;
    int size;
};

struct Node {
    struct Node* next;
    Item data;
};

Stack newStack(void) {
    Stack s;

    s = malloc(sizeof(struct Stack));
    if(s == NULL) return NULL;

    s->head = NULL;
    s->size = 0;

    return s;
}

int isEmpty(Stack s) {
    return (s->size) == 0;
}

int push(Stack s, Item it) {
    struct Node* new;
    
    new = malloc(sizeof(struct Node));
    if(new == NULL) return 0;
    
    new->data = it;
    
    new->next = s->head; 
    s->head = new;

    (s->size)++;
   
    return 1; 
}

int pop(Stack s) {
    struct Node* tmp;

    if(isEmpty(s)) return 0;

    tmp = s->head;
    s->head = s->head->next;
    free(tmp);
    
    (s->size)--;

    return 1;
}

Item top(Stack s){
    if(isEmpty(s)) return NULLITEM;

    return s->head->data;
}

void printStack(Stack s) {
    struct Node* head = s->head;
    int i = 0;

    while(head != NULL) {
        printf("Element %d = ", i);
        printItem(head->data);
        putchar('\n');
        head = head->next;
        i++;
    }
}

Stack reverseStack(Stack s) {
    struct Node *head = s->head;
    Stack reverse;
    Item val;
    
    reverse = newStack();

    while(head != NULL){
        val = head->data;
        push(reverse, val);
        head = head->next;
    }

    return reverse;
}

Stack merge(Stack s1, Stack s2) {
    struct Node *head_1 = s1->head;
    struct Node *head_2 = s2->head;
    Item val;

    Stack new;

    new = newStack();

    while(head_2 != NULL) {
        val = head_2->data;
        push(new, val);
        head_2 = head_2->next;
    }

    while(head_1 != NULL) {
        val = head_1->data;
        push(new, val);
        head_1 = head_1->next;
    }

    return new;
}

Stack deleteItems(Stack s, Item it) {
    struct Node *tmp, *new_head;
    struct Node *previous;

    // If the item is at the beginning change the references
    if(isEqual(it, s->head->data)) {
        tmp = s->head;
        s->head = s->head->next;
        free(tmp);
    }

    new_head = s->head;
    previous = s->head;

    while(s->head != NULL) {
        if(isEqual(it, s->head->data)) {
            tmp = s->head;
            s->head = s->head->next;
            previous->next = s->head;
            free(tmp);
        }
        else {
            previous = s->head;
            s->head = s->head->next;
        }
    }

    s->head = new_head;

    return s;
}

void freeStack(Stack s) {
    struct Node* tmp;

    while(s->head != NULL) {
        tmp = s->head;
        s->head = s->head->next;
        free(tmp);
    }

    free(s);
}
