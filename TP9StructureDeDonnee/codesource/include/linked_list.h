#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
} LinkedList;

LinkedList* createList();
void destroyList(LinkedList* list);
void insertFront(LinkedList* list, int value);
void insertEnd(LinkedList* list, int value);
int getFront(LinkedList* list);
int getEnd(LinkedList* list);
int findInList(LinkedList* list, int value);

#endif