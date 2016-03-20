#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "node.h"
#include <iostream>

class LinkedList {
 private:
  Node* firstNode;

 public:
  LinkedList();
  ~LinkedList();

  // Append integer if it's not already in the list
  void insert(int x);

  bool isEmpty();

  // Delete integer from list. Return whether or not the number was in the list.
  bool erase(int x);

  // Print list
  void print();

  // Get first number in list
  int head();

  // Get pointer to where an integer is in the list. If not in the list, return null pointer
  int* find(int x);
};

std::istream& operator>>(std::istream &in, LinkedList &list);

#endif
