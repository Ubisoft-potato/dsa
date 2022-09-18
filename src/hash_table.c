//
// Created by cyka on 2022/9/17.
//
#include "hash_table.h"

#include <math.h>
#include <stdlib.h>
#include <strings.h>

static ht_item* ht_new_item(const char* k, const char* v) {
  ht_item* item = malloc(sizeof(ht_item));
  item->key = strdup(k);
  item->value = strdup(v);
  return item;
}

static void ht_del_item(ht_item* item) {
  free(item->key);
  free(item->value);
  free(item);
}

// string key hash function
static int ht_hash(const char* s, const int a, const int m) {
  long hash = 0;
  const int len_s = (int)strlen(s);
  for (int i = 0; i < len_s; i++) {
    hash += (long)pow(a, len_s - (i + 1)) * s[i];
    hash = hash % m;
  }
  return (int)hash;
}

static int ht_get_hash(const char* s, const int num_buckets,
                       const int attempt) {
  //  TODO pow a prime
  const int hash_a = ht_hash(s, 1, num_buckets);
  const int hash_b = ht_hash(s, 2, num_buckets);
  return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

ht_hash_table* ht_new() {
  ht_hash_table* table = malloc(sizeof(ht_hash_table));
  // initial bucket count
  table->count = 53;
  table->size = 0;
  // allocate item buckets
  table->items = calloc(table->count, sizeof(ht_item*));

  return NULL;
}

void ht_del_hash_table(ht_hash_table* ht) {
  for (int i = 0; i < ht->size; ++i) {
    ht_item* item = ht->items[i];
    if (item) {
      ht_del_item(item);
    }
  }
  free(ht->items);
  free(ht);
}

void ht_insert(ht_hash_table* ht, const char* key, const char* value) {
  ht_item* item = ht_new_item(key, value);
  int index = ht_get_hash(key, ht->size, 0);
  ht_item* cur_item = ht->items[index];
  int i = 1;
  while (cur_item != NULL) {
    index = ht_get_hash(key, ht->size, i);
    cur_item = ht->items[index];
    i++;
  }
  ht->items[index] = item;
  ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key) {
  int index = ht_get_hash(key, ht->size, 0);
  ht_item* cur_item = ht->items[index];
  int i = 1;
  while (cur_item != NULL) {
    if (strcmp(cur_item->key, key) == 0) {
      return cur_item->value;
    }
    index = ht_get_hash(key, ht->size, i);
    cur_item = ht->items[index];
    i++;
  }
  return NULL;
}

void ht_delete(ht_hash_table* h, const char* key) {

}
