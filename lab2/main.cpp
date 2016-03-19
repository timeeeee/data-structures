#include <iostream>
#include <fstream>
#include "hashTable.h"

int main(int argc, char * argv[]) {
  if (argc != 2) {
    std::cout << "\nUsage: lab2 datafile\n\n";
    return 0;
  }

  std::ifstream file;
  file.open(argv[1], std::ios::in);
  if (!file) {
    std::cout << "Could not open " << argv[1] << std::endl;
  }

  int tableSize;
  file >> tableSize;
  HashTable table(tableSize);
  std::cout << "created hash table of size " << tableSize << std::endl;

  // Read numbers from file and add them to table
  while (file) {
    file >> table;
  }
  std::cout << std::endl;

  table.print();
  std::cout << std::endl;

  std::cout << "remove 17, remove 14\n";
  table.remove(17); table.remove(14);
  table.print();
  std::cout << std::endl;

  std::cout << "insert 2, insert 25, insert 13\n";
  table.insert(2); table.insert(25); table.insert(13);
  table.print();
  std::cout << std::endl;

  return 0;
}
