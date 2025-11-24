#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(10 * sizeof(int));
    stack->top = -1;
    stack->capacity = 10;
    return stack;
}

void destroyStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

void push(Stack* stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->top++;
        stack->data[stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (stack->top >= 0) {
        int value = stack->data[stack->top];
        stack->top--;
        return value;
    }
    return -1;
}

int peek(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    }
    return -1;
}

int isEmptyStack(Stack* stack) {
    return stack->top == -1;
}