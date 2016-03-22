#ifndef __OPENHASHTABLE_H__
#define __OPENHASHTABLE_H__

#include "linkedList.h"
#include <iostream>

class OpenHashTable {
 private:
  LinkedList** lists;
  int modulus;

 public:
  OpenHashTable(int size);
  ~OpenHashTable();

  // Append integer if it's not already in the table
  void insert(int key);

  // Delete integer from table. Return whether or not the number was in the table
  bool remove(int key);

  // Print table
  void print();

  // Return whether or not key is in the list
  bool find(int key);

  // Perform hash function on key and return index
  int hash(int key);
};

std::istream& operator>>(std::istream &in, OpenHashTable &table);

#endif
