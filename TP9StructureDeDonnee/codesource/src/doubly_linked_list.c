#include "doubly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

DoublyLinkedList* createDoublyList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void destroyDoublyList(DoublyLinkedList* list) {
    DListNode* current = list->head;
    while (current != NULL) {
        DListNode* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void insertDoublyFront(DoublyLinkedList* list, int value) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = list->head;
    
    if (list->head != NULL) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode;
    }
    list->head = newNode;
}

void insertDoublyEnd(DoublyLinkedList* list, int value) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = list->tail;
    
    if (list->tail != NULL) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;
}

void insertDoublyAfter(DoublyLinkedList* list, DListNode* node, int value) {
    if (node == NULL) return;
    
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = value;
    newNode->prev = node;
    newNode->next = node->next;
    
    if (node->next != NULL) {
        node->next->prev = newNode;
    } else {
        list->tail = newNode;
    }
    node->next = newNode;
}

int getDoublyFront(DoublyLinkedList* list) {
    if (list->head == NULL) return -1;
    return list->head->data;
}

int getDoublyEnd(DoublyLinkedList* list) {
    if (list->tail == NULL) return -1;
    return list->tail->data;
}

void removeDoublyFront(DoublyLinkedList* list) {
    if (list->head == NULL) return;
    
    DListNode* temp = list->head;
    list->head = list->head->next;
    
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    free(temp);
}

void removeDoublyEnd(DoublyLinkedList* list) {
    if (list->tail == NULL) return;
    
    DListNode* temp = list->tail;
    list->tail = list->tail->prev;
    
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(temp);
}