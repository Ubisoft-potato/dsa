//
// Created by cyka on 2022/9/13.
//

#include "generic_list.h"

void push(ListNode **head_ref, void *new_data, size_t data_size) {
  ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

  new_node->data = malloc(data_size);
  new_node->next = *head_ref;

  int i;
  for (i = 0; i < data_size; i++)
    *(char *)(new_node->data + i) = *(char *)(new_data + i);

  // Change head pointer as new node is added at the beginning
  (*head_ref) = new_node;
}

void printList(ListNode *node, fptr printFunc) {
  while (node != NULL) {
    (*printFunc)(node->data);
    node = node->next;
  }
}
