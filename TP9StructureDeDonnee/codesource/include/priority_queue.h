#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct {
    int* data;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue();
void destroyPriorityQueue(PriorityQueue* pq);
void pushPriority(PriorityQueue* pq, int value);
int popPriority(PriorityQueue* pq);
int peekPriority(PriorityQueue* pq);
int isEmptyPriority(PriorityQueue* pq);

#endif