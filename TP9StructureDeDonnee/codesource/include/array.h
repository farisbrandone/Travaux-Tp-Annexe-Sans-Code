#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
    int* data;
    int size;
    int capacity;
} Array;

Array* createArray();
void destroyArray(Array* arr);
void pushBack(Array* arr, int value);
int getAt(Array* arr, int index);
void setAt(Array* arr, int index, int value);
int findValue(Array* arr, int value);
int getSize(Array* arr);

#endif