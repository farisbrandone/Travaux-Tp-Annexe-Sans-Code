#include "array.h"
#include <stdlib.h>
#include <stdio.h>

Array* createArray() {
    Array* arr = (Array*)malloc(sizeof(Array));
    arr->data = (int*)malloc(10 * sizeof(int));
    arr->size = 0;
    arr->capacity = 10;
    return arr;
}

void destroyArray(Array* arr) {
    free(arr->data);
    free(arr);
}

void pushBack(Array* arr, int value) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int*)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size] = value;
    arr->size++;
}

int getAt(Array* arr, int index) {
    if (index < 0 || index >= arr->size) {
        return -1;
    }
    return arr->data[index];
}

void setAt(Array* arr, int index, int value) {
    if (index >= 0 && index < arr->size) {
        arr->data[index] = value;
    }
}

int findValue(Array* arr, int value) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int getSize(Array* arr) {
    return arr->size;
}