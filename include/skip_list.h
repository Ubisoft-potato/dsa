//
// Created by cyka on 2022/9/14.
//

#ifndef DATASTRUCTURE_C_SKIP_LIST_H
#define DATASTRUCTURE_C_SKIP_LIST_H

#include <math.h>
#include <stdlib.h>

typedef struct SkipListNode SkipListNode;
typedef struct SkipList SkipList;

typedef int (*compare)(void *, void *);

struct SkipListNode {
  //  data is used to store any value type in node
  void *data;
  //  forward array
  SkipListNode **forward;
};

struct SkipList {
  // max level limitation for current skipList
  int MAX_LEVEL;
  // P is the fraction of the nodes with level
  // i pointers also having level i+1 pointers
  float P;
  // current skipList level
  int level;
  // pointer to header node
  SkipListNode *header;
};

SkipList *init_skip_list(int max_level, float p);

#endif  // DATASTRUCTURE_C_SKIP_LIST_H
