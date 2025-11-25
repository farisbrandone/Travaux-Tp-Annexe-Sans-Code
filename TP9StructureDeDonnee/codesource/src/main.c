#include <stdio.h>
#include "array.h"
#include "linked_list.h"
#include "doubly_linked_list.h"
#include "stack.h"
#include "queue.h"
#include "priority_queue.h"
#include "bst.h"
#include "rbtree.h"
#include "graph.h"
#include "hash_table.h"
#include "tree.h"

void demoArray() {
    printf("=== ARRAY DEMO ===\n");
    Array* arr = createArray();
    
    pushBack(arr, 10);
    pushBack(arr, 20);
    pushBack(arr, 30);
    
    printf("Array contents: ");
    for (int i = 0; i < getSize(arr); i++) {
        printf("%d ", getAt(arr, i));
    }
    printf("\n");
    
    setAt(arr, 1, 25);
    printf("After set index 1 to 25: ");
    for (int i = 0; i < getSize(arr); i++) {
        printf("%d ", getAt(arr, i));
    }
    printf("\n");
    
    printf("Find value 30 at index: %d\n", findValue(arr, 30));
    
    destroyArray(arr);
}

void demoLinkedList() {
    printf("\n=== LINKED LIST DEMO ===\n");
    LinkedList* list = createList();
    
    insertFront(list, 10);
    insertEnd(list, 30);
    insertFront(list, 5);
    insertEnd(list, 40);
    
    printf("Front: %d\n", getFront(list));
    printf("End: %d\n", getEnd(list));
    printf("Find 30 at index: %d\n", findInList(list, 30));
    
    destroyList(list);
}

void demoStack() {
    printf("\n=== STACK DEMO ===\n");
    Stack* stack = createStack();
    
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    printf("Peek: %d\n", peek(stack));
    printf("Pop: %d\n", pop(stack));
    printf("Pop: %d\n", pop(stack));
    printf("Is empty: %s\n", isEmptyStack(stack) ? "yes" : "no");
    
    destroyStack(stack);
}

void demoQueue() {
    printf("\n=== QUEUE DEMO ===\n");
    Queue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    printf("Front: %d\n", front(queue));
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Is empty: %s\n", isEmptyQueue(queue) ? "yes" : "no");
    
    destroyQueue(queue);
}

void demoTree() {
    printf("\n=== BINARY TREE DEMO ===\n");
    BinaryTree* tree = createTree();
    
    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 60);
    insert(tree, 80);
    
    printf("In-order traversal: ");
    printInOrder(tree);
    
    printf("Search 40: %s\n", search(tree, 40) ? "found" : "not found");
    printf("Search 100: %s\n", search(tree, 100) ? "found" : "not found");
    
    destroyTree(tree);
}

void demoHashTable() {
    printf("\n=== HASH TABLE DEMO ===\n");
    HashTable* table = createHashTable();
    
    insertHash(table, "Alice", 25);
    insertHash(table, "Bob", 30);
    insertHash(table, "Charlie", 35);
    
    printf("Alice: %d\n", getHash(table, "Alice"));
    printf("Bob: %d\n", getHash(table, "Bob"));
    printf("Contains David: %s\n", containsHash(table, "David") ? "yes" : "no");
    
    insertHash(table, "Alice", 26);
    printf("Alice after update: %d\n", getHash(table, "Alice"));
    
    destroyHashTable(table);
}

void demoDoublyLinkedList() {
    printf("\n=== DOUBLY LINKED LIST DEMO ===\n");
    DoublyLinkedList* list = createDoublyList();
    
    insertDoublyFront(list, 10);
    insertDoublyEnd(list, 30);
    insertDoublyFront(list, 5);
    insertDoublyEnd(list, 40);
    
    printf("Front: %d\n", getDoublyFront(list));
    printf("End: %d\n", getDoublyEnd(list));
    
    removeDoublyFront(list);
    printf("After remove front: %d\n", getDoublyFront(list));
    
    removeDoublyEnd(list);
    printf("After remove end: %d\n", getDoublyEnd(list));
    
    destroyDoublyList(list);
}

void demoPriorityQueue() {
    printf("\n=== PRIORITY QUEUE DEMO ===\n");
    PriorityQueue* pq = createPriorityQueue();
    
    pushPriority(pq, 30);
    pushPriority(pq, 10);
    pushPriority(pq, 20);
    pushPriority(pq, 5);
    
    printf("Priority queue: ");
    while (!isEmptyPriority(pq)) {
        printf("%d ", popPriority(pq));
    }
    printf("\n");
    
    destroyPriorityQueue(pq);
}

void demoBST() {
    printf("\n=== BINARY SEARCH TREE DEMO ===\n");
    BST* bst = createBST();
    
    insertBST(bst, 50);
    insertBST(bst, 30);
    insertBST(bst, 70);
    insertBST(bst, 20);
    insertBST(bst, 40);
    insertBST(bst, 60);
    insertBST(bst, 80);
    
    printf("BST in-order: ");
    printBSTInOrder(bst);
    
    printf("Min: %d, Max: %d\n", getMinBST(bst), getMaxBST(bst));
    printf("Search 40: %s\n", searchBST(bst, 40) ? "found" : "not found");
    printf("Search 100: %s\n", searchBST(bst, 100) ? "found" : "not found");
    
    removeBST(bst, 30);
    printf("After removing 30: ");
    printBSTInOrder(bst);
    
    destroyBST(bst);
}

void demoRBTree() {
    printf("\n=== RED-BLACK TREE DEMO ===\n");
    RBTree* rbt = createRBTree();
    
    insertRBTree(rbt, 50);
    insertRBTree(rbt, 30);
    insertRBTree(rbt, 70);
    insertRBTree(rbt, 20);
    insertRBTree(rbt, 40);
    insertRBTree(rbt, 60);
    insertRBTree(rbt, 80);
    
    printf("RBTree in-order: ");
    printRBTreeInOrder(rbt);
    
    printf("Search 40: %s\n", searchRBTree(rbt, 40) ? "found" : "not found");
    printf("Search 100: %s\n", searchRBTree(rbt, 100) ? "found" : "not found");
    
    destroyRBTree(rbt);
}

void demoGraph() {
    printf("\n=== GRAPH DEMO ===\n");
    Graph* graph = createGraph(5);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    
    printf("Graph adjacency lists:\n");
    printGraph(graph);
    
    BFS(graph, 0);
    DFS(graph, 0);
    
    destroyGraph(graph);
}

int main() {
    printf("🚀 COMPLETE DATA STRUCTURES DEMO\n\n");
    
    demoArray();
    demoLinkedList();
    demoDoublyLinkedList();
    demoStack();
    demoQueue();
    demoPriorityQueue();
    demoBST();
    demoRBTree();
    demoGraph();
    demoHashTable();
    demoTree();
    
    printf("\n✅ All demos completed!\n");
    return 0;
}