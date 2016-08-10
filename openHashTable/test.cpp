#include <iostream>
#include <fstream>
#include <cassert>

#include "hashTable.h"

int main() {
  {
    HashTable table(7);
  
    // When table is empty, we shouldn't find any numbers
    for (int i = 0; i < 100; i++) {
      assert(!table.find(i));
    }
  
    // With empty table, trying to remove numbers should also return false
    for (int i = 0; i < 100; i++) {
      assert(!table.remove(i));
    }
  
    // insert odd numbers to 19
    for (int i = 1; i < 20; i += 2) {
      table.insert(i);
    }
  
    for (int i = 0; i < 10; i++) {
      assert(!table.find(i * 2)); // can't find even number
      assert(table.find(i * 2 + 1)); // can find odd one
    }
  
    for (int i = 0; i < 10; i++) {
      assert(!table.remove(i * 2)); // can't remove even numbers
      assert(table.remove(i * 2 + 1)); // can remove odd ones
    }
  
    // now the table is empty?
    for (int i = 0; i < 20; i++) {
      assert(!table.find(i));
      assert(!table.remove(i));
    }
  
    // We can insert a key a bunch of times, but only remove it once
    for (int times = 0; times < 20; times++) {
      table.insert(5);
    }
    assert(table.find(5));
    assert(table.remove(5));
    assert(!table.find(5));
    assert(!table.remove(5));
  }

  // Read from a file
  {
    std::ifstream infile;
    infile.open("data.txt");
    if (!infile) {
      std::cerr << "data.txt not found.\n";
      return 1;
    }

    // data.txt should contain:
    // 5 16 12 17 4 2 16 14 12 3 8 15
    HashTable table(7);
    while (!infile.eof()) infile >> table;
    table.print();
    
    int numbers[] = {5, 16, 12, 17, 4, 2, 16, 14, 12, 3, 8, 15};
    for (int i = 0; i < 12; i++) {
      assert(table.find(numbers[i]));
    }

    // When this table goes out of scope with populated lists, we will expect
    // all dynamically allocated memory to get deleted properly.
  }

  std::cout << "All tests passed!\n";
    
  return 0;
}
