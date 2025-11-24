#ifndef RBTREE_H
#define RBTREE_H

typedef enum { RED, BLACK } Color;

typedef struct RBNode {
    int key;
    Color color;
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
} RBNode;

typedef struct {
    RBNode* root;
    RBNode* nil;
} RBTree;

RBTree* createRBTree();
void destroyRBTree(RBTree* tree);
void insertRBTree(RBTree* tree, int key);
int searchRBTree(RBTree* tree, int key);
void removeRBTree(RBTree* tree, int key);
void printRBTreeInOrder(RBTree* tree);

#endif