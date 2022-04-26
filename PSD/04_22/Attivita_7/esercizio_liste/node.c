#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct Node {
     Item data;
     struct Node *next;
};

Node newNode(Item it) {
    Node new; 

    new = malloc(sizeof(struct Node));
    if(new == NULL) return NULL;

    // Set the next pointer to NULL and give the data to the node
    new->next = NULL;
    new->data = it;
    
    return new;
}

int isNull(Node node) {
    return node == NULL;
}

Node nextNode(Node node) {
    node = node->next;

    return node;
}

Node addHead(Node head, Item it) {
    Node new; 

    new = newNode(it);
    if(new == NULL) return NULL;

    // If there are no nodes, set the created one as head 
    if(head == NULL) {
        head = new; 
        return head;
    }

    // Make the next of the new node as head
    new->next = head; 
    // Move the head to point to the new node
    head = new; 

    return head;
}

Node addTail(Node head, Item it) {
    Node new;

    new = newNode(it);
    if(new == NULL) return NULL;

    // If there are no nodes, set the created one as head 
    if(head == NULL) {
        head = new;
        return head;
    }

    Node last = head;
    Node new_head = head;

    // Traverse until the last node 
    while(last->next != NULL) {
        last = nextNode(last);
    }

    // Change the next of last node
    last->next = new;

    return new_head;

    /* The new node node will already point to NULL
    *  thanks to the newNode function
    */
}

Node addPos(Node head, Item it, int pos) {
    Node new;
    int i = 0;

    new = newNode(it);
    if(new == NULL) return NULL;

    // If there are no nodes, set the created one as head 
    if(head == NULL) {
        head = new;
        return head;
    }

    // If the position is 0, add the node to the head
    if(pos == 0) {
        new->next = head;
        head = new;
        return head;
    }

    Node previous, new_head;

    previous = head;
    new_head = head;

    // Traverse until the given pos - 1 is found or you reach the end of the list 
    while(i < pos - 1 && !isNull(previous)) {
        previous = nextNode(previous);
        i++;
    }

    // If the position doesn't exist return null
    if(previous == NULL) {
        free(new);
        return NULL;
    }

    /* If the position is found, set the new node to the given
    *  position and its next node to the current one that was in
    *  that position
    */
    new->next = previous->next;
    previous->next = new;

    return new_head;
}

Node removeNode(Node head, Item it) {
    Node tmp;

    tmp = head;

    // If there are no nodes, there is nothing to delete
    if(head == NULL) return NULL;

    /* If the data is at head set head to next node
    *  and free the previous head
    */
    if(isEqual(it, getItem(head))) {
        head = head->next;
        /* If the items are allocated they will be deallocated 
        *  You can comment this line if you don't need it (XXX)
        */
        // freeItem(tmp->data);
        free(tmp);
        return head;
    }

    Node previous, new_head;

    previous = head;
    new_head = head;

    // Traverse until the data is found or you reach the end of the list 
    while(!isEqual(it, getItem(tmp)) && !isNull(tmp)) {
        previous = tmp;
        tmp = nextNode(tmp);
    }

    // Data not found
    if(tmp == NULL) return NULL;

    /* If the data is found set the next pointer of the previous node
    *  to the next node of the node to delete
    */
    previous->next = tmp->next;

    /* If the items are allocated they will be deallocated 
    *  You can comment this line if you don't need it (XXX)
    */
    // freeItem(tmp->data);

    // Deallocate the node
    free(tmp);

    return new_head;
}

Node removePos(Node head, int pos) {
    int i = 0;

    // If there are no nodes, there is nothing to delete
    if(head == NULL) return NULL;

    Node tmp;

    // If the position is 0, remove the head
    if(pos == 0) {
        tmp = head;
        head = head->next;
        /* If the items are allocated they will be deallocated 
        *  You can comment this line if you don't need it (XXX)
        */
        // freeItem(tmp->data);

        // Deallocate the node
        free(tmp);
        return head;
    }

    Node previous, new_head;

    previous = head;
    new_head = head;

    // Traverse until the given pos - 1 is found or you reach the end of the list 
    while(i < pos - 1 && !isNull(previous)) {
        previous = nextNode(previous);
        i++;
    }

    // If the position doesn't exist return null
    if(previous == NULL) return NULL;
    if(previous->next == NULL) return NULL;

    // Give to tmp the next of the previous node (the node to delete)
    tmp = previous->next;

    /* If the pos is found set the next pointer of the previous node
    *  to the next node of the node to delete
    */
    previous->next = tmp->next;
    /* If the items are allocated they will be deallocated 
    *  You can comment this line if you don't need it (XXX)
    */
    // freeItem(tmp->data);
    free(tmp);

    return new_head;
}

Node setNode(Node head, Item it, int pos) {
    // Item tmp;
    int i = 0;

    // If there are no nodes, there is nothing to set
    if(head == NULL) return NULL;
    
    if(pos == 0) {
        // tmp = head->data;
        head->data = it;
        /* If the items are allocated they will be deallocated 
        *  You can comment this line if you don't need it (XXX)
        */  
        //freeItem(tmp);
        return head;
    }
    
    Node new_head;
    
    new_head = head;

    while(i < pos && !isNull(head)) {
        head = nextNode(head);
        i++;
    }
    
    // Data not found
    if(head == NULL) return NULL;
    
    // tmp = head->data;
    
    // If the position is found set the new value
    head->data = it;

    /* If the items are allocated they will be deallocated 
    *  You can comment this line if you don't need it (XXX)
    */  
    // freeItem(tmp);
    
    return new_head;
}

Item getItemPos(Node head, int pos) {
    int i = 0;

    // If there are no nodes, there is nothing to return
    if(head == NULL) return NULLITEM;

    // If the position is 0, return the value of the head
    if(pos == 0) {
        return getItem(head);
    }

    // Traverse until the given pos is found or you reach the end of the list 
    while(i < pos && !isNull(head)) {
        head = nextNode(head);
        i++;
    }

    // If the pos isn't found getItem will return NULLITEM
    return getItem(head);
}

Item getItem(Node node) {
    if(node != NULL) {
        return node->data;
    }

    return NULLITEM; 
}

int countNodes(Node head) {
    int size = 0;

    if(head == NULL) return size;


    // Count the nodesc
    while(!isNull(head)) {
        size++;
        head = nextNode(head);
    }

    return size;
}
