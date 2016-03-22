#ifndef __CLOSEDHASHTABLE_H__
#define __CLOSEDHASHTABLE_H__

#include <iostream>

class ClosedHashTable {
 private:
  int ** keys;
  bool * hasBeenDeleted;
  int numValues;
  int triesBeforeFail;

 protected:
  int modulus;

 public:
  ClosedHashTable(int size);
  ~ClosedHashTable();

  // Append integer if it's not already in the table
  void insert(int key);

  // Delete integer from table. Return whether or not the number was in the table
  bool remove(int key);

  // Print table
  void print();

  // Return whether or not key is in the list
  bool contains(int key);

  // Perform hash function on key and return index
  virtual int hash(int key, int i);

  // Return if the table is full
  bool isFull();
};

std::istream& operator>>(std::istream &in, ClosedHashTable &table);

class ClosedHashTableLinearProbing : public ClosedHashTable {
 public:
  ClosedHashTableLinearProbing(int size);
  int hash(int key, int i);
};

class ClosedHashTableQuadraticProbing : public ClosedHashTable {
 public:
  ClosedHashTableQuadraticProbing(int size);
  int hash(int key, int i);
};

#endif
