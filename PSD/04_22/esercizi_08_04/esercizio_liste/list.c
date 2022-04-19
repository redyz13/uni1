#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.h"

struct List {
    struct Node *head;
    int size;
};

List newList(void) {
    List l; 
    
    l = malloc(sizeof(struct List));
    if(l == NULL) return NULL;

    // Set the head pointer to NULL and the size to 0
    l->head = NULL;
    l->size = 0;

    return l;
}

int isEmpty(List list) {
    return (list->size) == 0;
}

int addFirst(List list, Item it) {
    Node head = list->head;

    head = addHead(list->head, it);
    
    if(head == NULL) return 0;

    list->head = head;
    (list->size)++;

    return 1;
}

int addLast(List list, Item it) {
    Node head = list->head;

    head = addTail(list->head, it);
    
    if(head == NULL) return 0;

    list->head = head;
    (list->size)++;

    return 1;
}

int add(List list, Item it, int pos) {
    Node head = list->head;

    head = addPos(list->head, it, pos);
    
    if(head == NULL) return 0;

    list->head = head;
    (list->size)++;

    return 1;
}

int removeItem(List list, Item it) {
    Node head = list->head;

    head = removeNode(list->head, it);
   
    // Check if this is the last value to remove
    if(list->size > 1) {
        if(head == NULL) return 0;
    }

    list->head = head;
    (list->size)--;

    return 1;
}

int removeFirst(List list) {
    return removeItemPos(list, 0);
}

int removeLast(List list) {
    int size = (list->size) - 1;

    return removeItemPos(list, size);
}

int removeItemPos(List list, int pos) {
    Node head = list->head;

    head = removePos(list->head, pos);

    // Check if this is the last value to remove
    if(list->size > 1) {
        if(head == NULL) return 0;
    }
   
    list->head = head;
    (list->size)--;

    return 1;
}

int set(List list, Item it, int pos) {
    Node head = list->head;

    head = setNode(head, it, pos);
    
    if(head == NULL) return 0;

    list->head = head;

    return 1;
}

Item get(List list, int pos) {
    return getItemPos(list->head, pos);
}

Item getFirst(List list) {
    Node head = list->head;

    if(head == NULL) return NULLITEM;

    return getItem(head);
}

Item getLast(List list) {
    Node head = list->head;
    int size = (list->size) - 1;

    return getItemPos(head, size);
}

int contains(List list, Item it) {
    Node head = list->head; 
    
    while(!isNull(head)){
        if(isEqual(it, getItem(head))){
            return 1;
        }
        
        head = nextNode(head);
    }

    return 0;
}

int indexOf(List list, Item it) {
    Node head = list->head;
    int i = 0;

    while(!isNull(head)){
        if(isEqual(it, getItem(head))){
            return i;
        }
        
        i++;
        head = nextNode(head);
    }

    return -1;
}

List clone(List list) {
    Node head;
    Item val;

    head = list->head;
    
    if(head == NULL) return NULL;

    List clone;

    clone = newList();

    while(!isNull(head)){
        val = getItem(head);
        addLast(clone, val);
        head = nextNode(head);
    }

    return clone;
}

void printList(List list) {
    Node head = list->head;
    int i = 0;

    // Traverse through nodes of the list and print data of each node
    while(!isNull(head)) {
        printf("Element %d = ", i);
        printItem(getItem(head));
        putchar('\n');
        head = nextNode(head);
        i++;
    }
}

List reverseList(List list) {
    List reverse;
    Node head;
    Item val;

    head = list->head;

    reverse = newList();

    while(!isNull(head)){
        val = getItem(head);
        addFirst(reverse, val);
        head = nextNode(head);
    }
    
    freeList(list);

    return reverse;
}

void freeList(List list) {
    Node head, tmp;

    head = list->head;

    // Travers through nodes of the list and free each node
    while(!isNull(head)) {
        tmp = head;
        head = nextNode(head);
        free(tmp);
    }

    free(list);
}

// This function will also deallocate data (XXX)
void destroyList(List list) {
    Node head, tmp;

    head = list->head;

    // Travers through nodes of the list and free each node
    while(!isNull(head)) {
        tmp = head;
        freeItem(getItem(tmp));
        head = nextNode(head);
        free(tmp);
    }

    free(list);
}

int switchCoppie(List list) {
    Node head;
    Item it1, it2;

    head = list->head;

    if(head == NULL || nextNode(head) == NULL) return 0;

    for(int i = 0; i < (list->size) - 1; i += 2) {
        it1 = getItemPos(head, i);
        it2 = getItemPos(head, i + 1);

        set(list, it1, i + 1);
        set(list, it2, i);
    }

    return 1;
}

int eliminaCentro(List list) {
    Node head = list->head;

    int size = countNodes(head);

    // If there is no middle there's nothing to delete
    if(size % 2 == 0) return 0;

    removeItemPos(list, size / 2);

    return 1;
}
