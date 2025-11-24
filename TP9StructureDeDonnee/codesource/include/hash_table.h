#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct HashEntry {
    char* key;
    int value;
    struct HashEntry* next;
} HashEntry;

typedef struct {
    HashEntry** buckets;
    int capacity;
} HashTable;

HashTable* createHashTable();
void destroyHashTable(HashTable* table);
void insertHash(HashTable* table, const char* key, int value);
int getHash(HashTable* table, const char* key);
int containsHash(HashTable* table, const char* key);

#endif