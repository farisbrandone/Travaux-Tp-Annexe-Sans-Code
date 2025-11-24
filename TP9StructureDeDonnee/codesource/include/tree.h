#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
} BinaryTree;

BinaryTree* createTree();
void destroyTree(BinaryTree* tree);
void insert(BinaryTree* tree, int value);
int search(BinaryTree* tree, int value);
void printInOrder(BinaryTree* tree);

#endif