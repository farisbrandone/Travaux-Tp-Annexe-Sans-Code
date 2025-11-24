#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

static BSTNode* createBSTNode(int key) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static void destroyBSTNodes(BSTNode* node) {
    if (node != NULL) {
        destroyBSTNodes(node->left);
        destroyBSTNodes(node->right);
        free(node);
    }
}

static BSTNode* insertBSTNode(BSTNode* node, int key) {
    if (node == NULL) {
        return createBSTNode(key);
    }
    
    if (key < node->key) {
        node->left = insertBSTNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertBSTNode(node->right, key);
    }
    
    return node;
}

static int searchBSTNode(BSTNode* node, int key) {
    if (node == NULL) return 0;
    if (key == node->key) return 1;
    if (key < node->key) return searchBSTNode(node->left, key);
    return searchBSTNode(node->right, key);
}

static BSTNode* findMinBSTNode(BSTNode* node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

static BSTNode* removeBSTNode(BSTNode* node, int key) {
    if (node == NULL) return NULL;
    
    if (key < node->key) {
        node->left = removeBSTNode(node->left, key);
    } else if (key > node->key) {
        node->right = removeBSTNode(node->right, key);
    } else {
        if (node->left == NULL) {
            BSTNode* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            BSTNode* temp = node->left;
            free(node);
            return temp;
        }
        
        BSTNode* temp = findMinBSTNode(node->right);
        node->key = temp->key;
        node->right = removeBSTNode(node->right, temp->key);
    }
    
    return node;
}

static void printBSTInOrderNode(BSTNode* node) {
    if (node != NULL) {
        printBSTInOrderNode(node->left);
        printf("%d ", node->key);
        printBSTInOrderNode(node->right);
    }
}

static int getMinBSTNode(BSTNode* node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node != NULL ? node->key : -1;
}

static int getMaxBSTNode(BSTNode* node) {
    while (node != NULL && node->right != NULL) {
        node = node->right;
    }
    return node != NULL ? node->key : -1;
}

BST* createBST() {
    BST* tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}

void destroyBST(BST* tree) {
    destroyBSTNodes(tree->root);
    free(tree);
}

void insertBST(BST* tree, int key) {
    tree->root = insertBSTNode(tree->root, key);
}

int searchBST(BST* tree, int key) {
    return searchBSTNode(tree->root, key);
}

void removeBST(BST* tree, int key) {
    tree->root = removeBSTNode(tree->root, key);
}

void printBSTInOrder(BST* tree) {
    printBSTInOrderNode(tree->root);
    printf("\n");
}

int getMinBST(BST* tree) {
    return getMinBSTNode(tree->root);
}

int getMaxBST(BST* tree) {
    return getMaxBSTNode(tree->root);
}