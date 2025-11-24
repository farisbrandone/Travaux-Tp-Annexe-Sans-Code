#ifndef STACK_H
#define STACK_H

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack();
void destroyStack(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
int isEmptyStack(Stack* stack);

#endif