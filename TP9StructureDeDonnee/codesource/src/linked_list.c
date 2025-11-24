#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void destroyList(LinkedList* list) {
    ListNode* current = list->head;
    while (current != NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void insertFront(LinkedList* list, int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

void insertEnd(LinkedList* list, int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        ListNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int getFront(LinkedList* list) {
    if (list->head == NULL) {
        return -1;
    }
    return list->head->data;
}

int getEnd(LinkedList* list) {
    if (list->head == NULL) {
        return -1;
    }
    
    ListNode* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->data;
}

int findInList(LinkedList* list, int value) {
    ListNode* current = list->head;
    int index = 0;
    
    while (current != NULL) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}