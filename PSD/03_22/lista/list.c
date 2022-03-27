#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

struct Node {
    item data;
    struct Node *next;
};

Node newNode(item x) {
    Node node;

    node = malloc(sizeof(struct Node));

    if(node == NULL) return NULL;

    // Set the next pointer to NULL and give the data to the node
    node->data= x;
    node->next = NULL;

    return node;
}

item getData(Node n) {
    return n->data;
}

void printList(Node head) {
    int i = 0;

    // Traverse through nodes and print data of each node
    while(head != NULL) {
        printf("Element %d = ", i++);
        printItem(head->data);
        putchar('\n');
        head = head->next;
    }
}

int countNodes(Node head) {
    int i = 1;

    // Return 0 if there are no nodes
    if(head == NULL) {
        return 0;
    }

    // Traverse through nodes and count them
    while(head->next != NULL) {
        head = head->next;
        i++;
    }

    return i;
}

void addEnd(Node *head, item x) {
    Node new, last;

    new = newNode(x);

    last = *head;

    if(new != NULL) {
        // If there are no nodes, set the created one as head 
        if(*head == NULL) {
            *head = new;
            return;
        }

        // Traverse until the last node
        while(last->next != NULL) {
            last = last->next;
        }

        // Change the next of last node
        last->next = new;

        /* The new node node will already point to NULL
        *  to the newNode function
        */
    }
}

void addFront(Node *head, item x) {
    Node new;

    new = newNode(x);

    // If there are no nodes, set the created one as head 
    if(*head == NULL) {
        *head = new;
        return;
    }

    if(new != NULL) {
        // Make the next of the new node as head
        new->next = *head;
        // Move the head to point to the new node
        *head = new;
    }
}

void freeList(Node head) {
    Node tmp;

    // Travers through nodes and free each node
    while(head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void removeNode(Node *head, item x) {
    Node tmp, previous;

    tmp = *head;

    /* If the data is at head set head to next node
    *  and free the previous head
    */
    if(getData(*head) == x) {
        *head = (*head)->next;
        free(tmp);
        return;
    }

    // Traverse until the data is found or you reach the end of the list 
    while(getData(tmp) != x && tmp->next != NULL) {
        // Take trace of the node before the one to delete
        previous = tmp;
        tmp = tmp->next;
    }

    /* If the data is found set the next pointer of the previous node
    *  to the next node of the node to delete
    */
    if(tmp != NULL) {
        previous->next = tmp->next;
        // Free the node
        free(tmp);
    }
}

void reverseList(Node *head) {
    Node prev = NULL;
    Node current = *head;
    Node next = NULL;

    while(current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }

    *head = prev;
}
