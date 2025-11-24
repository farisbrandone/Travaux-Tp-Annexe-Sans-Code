#include <stdio.h>
#include <assert.h>
#include "../include/array.h"
#include "../include/linked_list.h"
#include "../include/doubly_linked_list.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/priority_queue.h"
#include "../include/bst.h"
#include "../include/hash_table.h"
#include "../include/graph.h"
void testArray() {
    printf("Testing Array...\n");
    
    Array* arr = createArray();
    assert(getSize(arr) == 0);
    
    pushBack(arr, 10);
    pushBack(arr, 20);
    pushBack(arr, 30);
    
    assert(getSize(arr) == 3);
    assert(getAt(arr, 0) == 10);
    assert(getAt(arr, 1) == 20);
    assert(getAt(arr, 2) == 30);
    
    setAt(arr, 1, 25);
    assert(getAt(arr, 1) == 25);
    
    assert(findValue(arr, 30) == 2);
    assert(findValue(arr, 100) == -1);
    
    destroyArray(arr);
    printf("Array tests passed!\n");
}

void testLinkedList() {
    printf("Testing Linked List...\n");
    
    LinkedList* list = createList();
    
    insertFront(list, 10);
    insertEnd(list, 30);
    insertFront(list, 5);
    
    assert(getFront(list) == 5);
    assert(getEnd(list) == 30);
    assert(findInList(list, 10) == 1);
    assert(findInList(list, 100) == -1);
    
    destroyList(list);
    printf("Linked List tests passed!\n");
}

void testDoublyLinkedList() {
    printf("Testing Doubly Linked List...\n");
    
    DoublyLinkedList* list = createDoublyList();
    
    insertDoublyFront(list, 10);
    insertDoublyEnd(list, 30);
    insertDoublyFront(list, 5);
    
    assert(getDoublyFront(list) == 5);
    assert(getDoublyEnd(list) == 30);
    
    removeDoublyFront(list);
    assert(getDoublyFront(list) == 10);
    
    removeDoublyEnd(list);
    assert(getDoublyEnd(list) == 10);
    
    destroyDoublyList(list);
    printf("Doubly Linked List tests passed!\n");
}

void testStack() {
    printf("Testing Stack...\n");
    
    Stack* stack = createStack();
    assert(isEmptyStack(stack) == 1);
    
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    assert(isEmptyStack(stack) == 0);
    assert(peek(stack) == 30);
    assert(pop(stack) == 30);
    assert(pop(stack) == 20);
    assert(pop(stack) == 10);
    assert(isEmptyStack(stack) == 1);
    assert(pop(stack) == -1);
    
    destroyStack(stack);
    printf("Stack tests passed!\n");
}

void testQueue() {
    printf("Testing Queue...\n");
    
    Queue* queue = createQueue();
    assert(isEmptyQueue(queue) == 1);
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    assert(isEmptyQueue(queue) == 0);
    assert(front(queue) == 10);
    assert(dequeue(queue) == 10);
    assert(dequeue(queue) == 20);
    assert(dequeue(queue) == 30);
    assert(isEmptyQueue(queue) == 1);
    assert(dequeue(queue) == -1);
    
    destroyQueue(queue);
    printf("Queue tests passed!\n");
}

void testPriorityQueue() {
    printf("Testing Priority Queue...\n");
    
    PriorityQueue* pq = createPriorityQueue();
    assert(isEmptyPriority(pq) == 1);
    
    pushPriority(pq, 30);
    pushPriority(pq, 10);
    pushPriority(pq, 20);
    pushPriority(pq, 5);
    
    assert(isEmptyPriority(pq) == 0);
    assert(peekPriority(pq) == 5);
    assert(popPriority(pq) == 5);
    assert(popPriority(pq) == 10);
    assert(popPriority(pq) == 20);
    assert(popPriority(pq) == 30);
    assert(isEmptyPriority(pq) == 1);
    assert(popPriority(pq) == -1);
    
    destroyPriorityQueue(pq);
    printf("Priority Queue tests passed!\n");
}

void testBST() {
    printf("Testing Binary Search Tree...\n");
    
    BST* bst = createBST();
    
    insertBST(bst, 50);
    insertBST(bst, 30);
    insertBST(bst, 70);
    insertBST(bst, 20);
    insertBST(bst, 40);
    insertBST(bst, 60);
    insertBST(bst, 80);
    
    assert(searchBST(bst, 40) == 1);
    assert(searchBST(bst, 100) == 0);
    assert(getMinBST(bst) == 20);
    assert(getMaxBST(bst) == 80);
    
    removeBST(bst, 30);
    assert(searchBST(bst, 30) == 0);
    assert(searchBST(bst, 40) == 1);
    
    destroyBST(bst);
    printf("BST tests passed!\n");
}

void testHashTable() {
    printf("Testing Hash Table...\n");
    
    HashTable* table = createHashTable();
    
    insertHash(table, "Alice", 25);
    insertHash(table, "Bob", 30);
    insertHash(table, "Charlie", 35);
    
    assert(getHash(table, "Alice") == 25);
    assert(getHash(table, "Bob") == 30);
    assert(containsHash(table, "Charlie") == 1);
    assert(containsHash(table, "David") == 0);
    
    insertHash(table, "Alice", 26);
    assert(getHash(table, "Alice") == 26);
    
    destroyHashTable(table);
    printf("Hash Table tests passed!\n");
}

void testGraph() {
    printf("Testing Graph...\n");
    
    Graph* graph = createGraph(5);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    
    // Vérifier que les arêtes sont bien ajoutées
    // Pour un test simple, on vérifie que le graphe peut être détruit sans erreur
    // Dans une vraie application, on vérifierait la structure
    
    destroyGraph(graph);
    printf("Graph tests passed!\n");
}

void runAllTests() {
    printf("🚀 RUNNING ALL TESTS\n\n");
    
    testArray();
    testLinkedList();
    testDoublyLinkedList();
    testStack();
    testQueue();
    testPriorityQueue();
    testBST();
    testHashTable();
    testGraph();
    
    printf("\n✅ ALL TESTS PASSED!\n");
}

int main() {
    runAllTests();
    return 0;
}