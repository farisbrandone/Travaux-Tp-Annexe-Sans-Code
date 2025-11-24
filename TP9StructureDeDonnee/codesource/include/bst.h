#ifndef BST_H
#define BST_H

typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct {
    BSTNode* root;
} BST;

BST* createBST();
void destroyBST(BST* tree);
void insertBST(BST* tree, int key);
int searchBST(BST* tree, int key);
void removeBST(BST* tree, int key);
void printBSTInOrder(BST* tree);
int getMinBST(BST* tree);
int getMaxBST(BST* tree);

#endif