#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(10 * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = 10;
    return queue;
}

void destroyQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

void enqueue(Queue* queue, int value) {
    if ((queue->rear + 1) % queue->capacity != queue->front || 
        (queue->rear == -1 && queue->front == 0)) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->data[queue->rear] = value;
    }
}

int dequeue(Queue* queue) {
    if (queue->rear == -1) {
        return -1;
    }
    
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = 0;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return value;
}

int front(Queue* queue) {
    if (queue->rear == -1) {
        return -1;
    }
    return queue->data[queue->front];
}

int isEmptyQueue(Queue* queue) {
    return queue->rear == -1;
}