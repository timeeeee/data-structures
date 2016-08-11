#include <iostream>

#include "../linkedList/linkedList.h"
#include "hashTable.h"

HashTable::HashTable (int size) {
  lists = new LinkedList*[size];
  for (int i = 0; i < size; i++) {
    lists[i] = new LinkedList;
  }

  modulus = size;
}

HashTable::~HashTable () {
  for (int i = 0; i < modulus; i++) {
    delete lists[i];
  }
  delete[] lists;
}

// Extremely simple hash function
int HashTable::hash(int key) {
  return key % modulus;
}

// Append integer if it's not already in the table
void HashTable::insert(int key) {
  lists[hash(key)]->insert(key);
}

// Delete integer from table. Return whether or not the key was in the table
bool HashTable::remove(int key) {
  return lists[hash(key)]->erase(key);
}

// Print table
void HashTable::print() {
  for (int i = 0; i < modulus; i++) {
    std::cout << i << ": ";
    lists[i]->print();
  }
  std::cout << std::endl;
}

// Return whether or not key is in the table
bool HashTable::find(int key) {
  int *key_in_list = lists[hash(key)]->find(key);
  return key_in_list != 0;
}

// Read a key from an istream into the table
std::istream& operator>>(std::istream &in, HashTable &table) {
  int key = 0;
  in >> key;
  table.insert(key);
  return in;
}
