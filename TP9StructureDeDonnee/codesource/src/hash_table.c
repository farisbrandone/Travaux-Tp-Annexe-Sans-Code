#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static unsigned int hashFunction(const char* key, int capacity) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = hash * 31 + key[i];
    }
    return hash % capacity;
}

HashTable* createHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->capacity = 10;
    table->buckets = (HashEntry**)calloc(table->capacity, sizeof(HashEntry*));
    return table;
}

void destroyHashTable(HashTable* table) {
    for (int i = 0; i < table->capacity; i++) {
        HashEntry* entry = table->buckets[i];
        while (entry != NULL) {
            HashEntry* next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free(table->buckets);
    free(table);
}

void insertHash(HashTable* table, const char* key, int value) {
    unsigned int index = hashFunction(key, table->capacity);
    
    HashEntry* entry = table->buckets[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    
    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = table->buckets[index];
    table->buckets[index] = newEntry;
}

int getHash(HashTable* table, const char* key) {
    unsigned int index = hashFunction(key, table->capacity);
    
    HashEntry* entry = table->buckets[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

int containsHash(HashTable* table, const char* key) {
    return getHash(table, key) != -1;
}