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
  HashTableLinearProbing tableLinear(tableSize);
  HashTableQuadraticProbing tableQuadratic(tableSize);
  std::cout << "created hash tables of size " << tableSize << std::endl;

  // Read numbers from file and add them to table
  while (file) {
    file >> table;
  }
  std::cout << std::endl;

  table.print();
  std::cout << std::endl;

  std::cout << "good so far\n";
  return 0;
}
