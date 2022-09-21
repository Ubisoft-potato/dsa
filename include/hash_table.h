//
// Created by cyka on 2022/9/17.
//

#ifndef DSA_HASH_TABLE_H
#define DSA_HASH_TABLE_H

// hash table key pair item
typedef struct {
    char* key;
    char* value;
} ht_item;

// hash table
typedef struct {
    int size;
    int count;
    ht_item** items;
} ht_hash_table;

ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);

void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* ht, const char* key);

#endif // DSA_HASH_TABLE_H
