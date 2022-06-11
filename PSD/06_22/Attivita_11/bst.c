#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

#define COUNT 10

struct Node {
    Item data;
    struct Node *left;
    struct Node *right;
};

Item getItem(BST t) {
    if (t == NULL) return NULLITEM;

    return t->data;
}

static void setItem(BST t, Item it) {
    if (t == NULL) return;

    t->data = it;
}

static BST creaFoglia(Item it) {
    BST foglia = malloc(sizeof(struct Node));
    if (foglia == NULL) return NULL;

    setItem(foglia, it);
    foglia->left = NULL;
    foglia->right = NULL;

    return foglia;
}

static BST minValue(BST t) {
    BST tmp = t;

    while (tmp->left != NULL)
        tmp = tmp->left;

    return tmp;
}

BST newBST(void) {
    return NULL;
}

int isEmpty(BST t) {
    return t == NULL;
}

int contains(BST t, Item it) {
    if (t == NULL) return 0;

    if (isEqual(getItem(t), it)) return 1;

    if (isMinus(getItem(t), it)) {
        return contains(t->right, it);
    }
    else {
        return contains(t->left, it);
    }
}

BST insertNode(BST t, Item it) {
    if (t == NULL) return creaFoglia(it);

    if (isMinus(it, getItem(t))) {
        t->left = insertNode(t->left, it);
    }
    else {
        t->right = insertNode(t->right, it);
    }

    return t;
}

BST deleteNode(BST t, Item it) {
    if (t == NULL) return NULL;

    if (isMinus(getItem(t), it))
        t->left = deleteNode(t->left, it);
    else if (isMinus(it, getItem(t)))
        t->right = deleteNode(t->right, it);
    else {
        if (t->left == NULL) {
            BST tmp = t->right;
            free(t);
            return tmp;
        }
        else if (t->right == NULL) {
            BST tmp = t->left;
            free(t);
            return tmp;
        }

        BST tmp = minValue(t->right);
        t->data = tmp->data;
        t->right = deleteNode(t->right, tmp->data);
    }

    return t;
}

static void print2DUtil(BST root, int space) {
    if (root == NULL) return;
 
    space += COUNT;
 
    print2DUtil(root->right, space);
 
    printf("\n");

    for (int i = COUNT; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);
 
    print2DUtil(root->left, space);
}
 
void print2D(BST root) {
   print2DUtil(root, 0);
}
