#include "priority_queue.h"
#include <stdlib.h>
#include <stdio.h>

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyUp(PriorityQueue* pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->data[parent] <= pq->data[index]) break;
        swap(&pq->data[parent], &pq->data[index]);
        index = parent;
    }
}

static void heapifyDown(PriorityQueue* pq, int index) {
    int size = pq->size;
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        
        if (left < size && pq->data[left] < pq->data[smallest]) {
            smallest = left;
        }
        if (right < size && pq->data[right] < pq->data[smallest]) {
            smallest = right;
        }
        if (smallest == index) break;
        
        swap(&pq->data[index], &pq->data[smallest]);
        index = smallest;
    }
}

PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->capacity = 10;
    pq->size = 0;
    pq->data = (int*)malloc(pq->capacity * sizeof(int));
    return pq;
}

void destroyPriorityQueue(PriorityQueue* pq) {
    free(pq->data);
    free(pq);
}

void pushPriority(PriorityQueue* pq, int value) {
    if (pq->size >= pq->capacity) {
        pq->capacity *= 2;
        pq->data = (int*)realloc(pq->data, pq->capacity * sizeof(int));
    }
    
    pq->data[pq->size] = value;
    heapifyUp(pq, pq->size);
    pq->size++;
}

int popPriority(PriorityQueue* pq) {
    if (pq->size == 0) return -1;
    
    int minValue = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    
    return minValue;
}

int peekPriority(PriorityQueue* pq) {
    if (pq->size == 0) return -1;
    return pq->data[0];
}

int isEmptyPriority(PriorityQueue* pq) {
    return pq->size == 0;
}