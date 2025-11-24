#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

BinaryTree* createTree() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    tree->root = NULL;
    return tree;
}

static void destroyTreeNode(TreeNode* node) {
    if (node != NULL) {
        destroyTreeNode(node->left);
        destroyTreeNode(node->right);
        free(node);
    }
}

void destroyTree(BinaryTree* tree) {
    destroyTreeNode(tree->root);
    free(tree);
}

static TreeNode* createTreeNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static TreeNode* insertTreeNode(TreeNode* node, int value) {
    if (node == NULL) {
        return createTreeNode(value);
    }
    
    if (value < node->value) {
        node->left = insertTreeNode(node->left, value);
    } else if (value > node->value) {
        node->right = insertTreeNode(node->right, value);
    }
    
    return node;
}

void insert(BinaryTree* tree, int value) {
    tree->root = insertTreeNode(tree->root, value);
}

static int searchTreeNode(TreeNode* node, int value) {
    if (node == NULL) {
        return 0;
    }
    if (value == node->value) {
        return 1;
    }
    if (value < node->value) {
        return searchTreeNode(node->left, value);
    }
    return searchTreeNode(node->right, value);
}

int search(BinaryTree* tree, int value) {
    return searchTreeNode(tree->root, value);
}

static void printInOrderTreeNode(TreeNode* node) {
    if (node != NULL) {
        printInOrderTreeNode(node->left);
        printf("%d ", node->value);
        printInOrderTreeNode(node->right);
    }
}

void printInOrder(BinaryTree* tree) {
    printInOrderTreeNode(tree->root);
    printf("\n");
}