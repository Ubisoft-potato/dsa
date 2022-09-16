//
// Created by cyka on 2022/9/11.
//
#include <gtest/gtest.h>

extern "C" {
#include "generic_list.h"
}

void handleIntElement(void *data) { printf(" %d", *(int *)data); }

// Demonstrate some basic assertions.
TEST(GeneticListTest, ListInsertNode) {
  ListNode *start = nullptr;

  // Create and print an int linked list
  unsigned int_size = sizeof(int);
  int arr[] = {10, 20, 30, 40, 50}, i;
  for (i = 4; i >= 0; i--) push(&start, arr + i, int_size);
  printf("Created integer linked list is \n");
  printList(start, handleIntElement);
}