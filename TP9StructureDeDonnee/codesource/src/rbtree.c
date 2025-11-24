#include "rbtree.h"
#include <stdlib.h>
#include <stdio.h>

static RBNode* createRBNode(int key, Color color, RBNode* nil) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->key = key;
    node->color = color;
    node->left = nil;
    node->right = nil;
    node->parent = nil;
    return node;
}

static void destroyRBNodes(RBTree* tree, RBNode* node) {
    if (node != tree->nil) {
        destroyRBNodes(tree, node->left);
        destroyRBNodes(tree, node->right);
        free(node);
    }
}

static void leftRotate(RBTree* tree, RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    
    if (y->left != tree->nil) {
        y->left->parent = x;
    }
    
    y->parent = x->parent;
    
    if (x->parent == tree->nil) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

static void rightRotate(RBTree* tree, RBNode* y) {
    RBNode* x = y->left;
    y->left = x->right;
    
    if (x->right != tree->nil) {
        x->right->parent = y;
    }
    
    x->parent = y->parent;
    
    if (y->parent == tree->nil) {
        tree->root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    
    x->right = y;
    y->parent = x;
}

static void insertFixup(RBTree* tree, RBNode* z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode* y = z->parent->parent->right;
            
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(tree, z->parent->parent);
            }
        } else {
            RBNode* y = z->parent->parent->left;
            
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

static int searchRBTreeNode(RBTree* tree, RBNode* node, int key) {
    if (node == tree->nil) return 0;
    if (key == node->key) return 1;
    if (key < node->key) return searchRBTreeNode(tree, node->left, key);
    return searchRBTreeNode(tree, node->right, key);
}

static void printRBTreeInOrderNode(RBTree* tree, RBNode* node) {
    if (node != tree->nil) {
        printRBTreeInOrderNode(tree, node->left);
        printf("%d(%s) ", node->key, node->color == RED ? "R" : "B");
        printRBTreeInOrderNode(tree, node->right);
    }
}

RBTree* createRBTree() {
    RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
    tree->nil = (RBNode*)malloc(sizeof(RBNode));
    tree->nil->color = BLACK;
    tree->nil->left = tree->nil;
    tree->nil->right = tree->nil;
    tree->nil->parent = tree->nil;
    tree->root = tree->nil;
    return tree;
}

void destroyRBTree(RBTree* tree) {
    destroyRBNodes(tree, tree->root);
    free(tree->nil);
    free(tree);
}

void insertRBTree(RBTree* tree, int key) {
    RBNode* z = createRBNode(key, RED, tree->nil);
    RBNode* y = tree->nil;
    RBNode* x = tree->root;
    
    while (x != tree->nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    
    z->parent = y;
    
    if (y == tree->nil) {
        tree->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    
    insertFixup(tree, z);
}

int searchRBTree(RBTree* tree, int key) {
    return searchRBTreeNode(tree, tree->root, key);
}

void removeRBTree(RBTree* tree, int key) {
    // Implémentation simplifiée - dans une vraie implémentation
    // il faudrait gérer tous les cas de suppression
    printf("RBTree remove not fully implemented\n");
}

void printRBTreeInOrder(RBTree* tree) {
    printRBTreeInOrderNode(tree, tree->root);
    printf("\n");
}