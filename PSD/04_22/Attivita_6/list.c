#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node {
    struct Node *next; 
    Punto val;
};

List newList(void) {
    return NULL;
}

int isEmpty(List l) {
    return l == NULL;
}

List tailList(List l) {
    if(l == NULL) return l;
    return l->next;
}

List addHead(List l, Punto p) {
    struct Node *new;
    
    new = malloc(sizeof(struct Node));
    
    if(new != NULL) {
        new->val = p;
        new->next = l;
        l = new;
    }

    return l;
}

void printList(List l) {
    int i = 0;

    while(!isEmpty(l)) {
        printf("Elemento %d: ", i);
        printItem(l->val);
        putchar('\n');
        l = tailList(l);
        i++;
    }
}

Punto getFirst(List l) {
    if(isEmpty(l)) return NULLITEM;

    return l->val;
}

int sizeList(List l) {
    if(isEmpty(l)) return 0;
    
    int i = 0;
    
    while(!isEmpty(l)) {
        l = tailList(l);
        i++;
    }

    return i;
}

// Torna la pos della prima occorrenza, altrimenti -1
int posItem(List l, Punto p) {
    if(isEmpty(l)) return -1;
    
    Punto tmp;
    int i = 0;

    while(!isEmpty(l)){
        tmp = getFirst(l);
        
        if(isEqual(p, tmp)){
            return i;
        }

        l = tailList(l);
        i++;
    }
    
    return -1;
}

int searchItem(List l, Punto p) {
    if(isEmpty(l)) return 0;

    Punto tmp;
    
    while(!isEmpty(l)) {
        tmp = getFirst(l);

        if(isEqual(tmp, p)) {
            return 1;
        }

        l = tailList(l);
    }

    return 0;
}

List reverseList(List l) {
    if(isEmpty(l)) return l;

    List rev;
    Punto tmp; 

    rev = newList();

    while(!isEmpty(l)) {
        tmp = getFirst(l);
        rev = addHead(rev, tmp);
        l = tailList(l);
    }

    return rev;
}

List removeItem(List l, Punto p) {
    if(isEmpty(l)) return l;

    List head = l;
    
    Punto val;
    List tmp;
    val = getFirst(l);

    if(isEqual(p, val)) {
        tmp = head;
        head = l->next;
        free(tmp);
        return head;
    }

    List prev;

    while(!isEmpty(l)) {
        val = getFirst(l);

        if(isEqual(p, val)){
            tmp = l;
            prev->next = l->next; 
            free(tmp);
            return head;
        }
        
        prev = l;
        l = tailList(l);
    }

    return head; 
}

// Ritorna l'item alla determinata posizione 
Punto getItem(List l, int pos) {
    if(isEmpty(l)) return NULLITEM;

    int i = 0;

    if(pos == 0) {
        return l->val;
    }

    while(i < pos && !isEmpty(l)) {
        l = tailList(l);
        i++;
    }

    if(l == NULL) return NULLITEM;

    return l->val;
}

// Inserisce l'item in una determinata posizione
List insertList(List l, Punto p, int pos) {
    struct Node *new;

    new = malloc(sizeof(struct Node));
    if(new == NULL) return l;

    new->val = p;
    new->next = NULL;

    if(pos == 0) {
        new->next = l;
        l = new;
        return l;
    }

    List prev;
    
    prev = l;

    int i = 0;

    while(i < pos - 1 && !isEmpty(prev)) {
        prev = tailList(prev);
        i++;
    }

    if(prev == NULL) {
        free(new);
        return l;
    }

    new->next = prev->next;
    prev->next = new;

    return l;
}

// Elimina l'elemento in una determinata posizione
List removeList(List l, int pos) {
    if(isEmpty(l)) return l;

    List tmp = l;

    if(pos == 0) {
        l = tailList(l);
        free(tmp);
        return l;
    }

    List prev;
    
    prev = l;

    int i = 0;

    while(i < pos - 1 && !isEmpty(prev)) {
        prev = tailList(prev);
        i++;
    }

    if(prev == NULL) return l;
    if(prev->next == NULL) return l;

    tmp = prev->next;
    prev->next = tmp->next;

    free(tmp);

    return l;
}
