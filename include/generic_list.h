//
// Created by cyka on 2022/9/13.
//

#ifndef DATASTRUCTURE_C_GENERIC_LIST_H
#define DATASTRUCTURE_C_GENERIC_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node ListNode;

typedef void (*fptr)(void *);

struct Node {
  // any data type can be store there
  void *data;
  ListNode *next;
};

void push(ListNode **head_ref, void *new_data, size_t data_size);

void printList(ListNode *node, fptr printFunc);

// Function to print an integer
void handleIntElement(void *data);

#endif  // DATASTRUCTURE_C_GENERIC_LIST_H
