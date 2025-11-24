#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DListNode {
    int data;
    struct DListNode* prev;
    struct DListNode* next;
} DListNode;

typedef struct {
    DListNode* head;
    DListNode* tail;
} DoublyLinkedList;

DoublyLinkedList* createDoublyList();
void destroyDoublyList(DoublyLinkedList* list);
void insertDoublyFront(DoublyLinkedList* list, int value);
void insertDoublyEnd(DoublyLinkedList* list, int value);
void insertDoublyAfter(DoublyLinkedList* list, DListNode* node, int value);
int getDoublyFront(DoublyLinkedList* list);
int getDoublyEnd(DoublyLinkedList* list);
void removeDoublyFront(DoublyLinkedList* list);
void removeDoublyEnd(DoublyLinkedList* list);

#endif