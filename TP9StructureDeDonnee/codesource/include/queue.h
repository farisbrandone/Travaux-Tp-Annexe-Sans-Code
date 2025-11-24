#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue();
void destroyQueue(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
int front(Queue* queue);
int isEmptyQueue(Queue* queue);

#endif