#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "../linkedList/linkedList.h"
#include <iostream>

class HashTable {
 private:
  LinkedList** lists;
  int modulus;

  // Perform hash function on key and return index
  int hash(int key);

 public:
  HashTable(int size);
  ~HashTable();

  // Append integer if it's not already in the table
  void insert(int key);

  // Delete integer from table. Return whether or not the number was in the table
  bool remove(int key);

  // Print table
  void print();

  // Return whether or not key is in the list
  bool find(int key);
};

std::istream& operator>>(std::istream &in, HashTable &table);

#endif
