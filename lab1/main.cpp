#include <iostream>
#include <fstream>
#include "linkedList.h"

int main() {
  LinkedList list;

  std::cout << std::endl;
  std::cout << "Declared linked list.\n";
  // Test isEmpty
  std::cout << "Is list empty: " << list.isEmpty() << std::endl;

  // Fill list
  std::cout << "Reading data from data.txt- ";
  std::ifstream infile;
  infile.open("data.txt");
  if (!infile) {
    std::cout << "data.txt not found.\n";
    return 1;
  }
  while (infile) {
    infile >> list;
  }

  std::cout << "Filled list.\n";
  // Test isEmpty
  std::cout << "Is list empty: " << list.isEmpty() << std::endl << std::endl;

  // Test print
  std::cout << "List: ";
  list.print();
  std::cout << std::endl;

  // Test erase
  list.erase(0);
  std::cout << "List after deleting 0: ";
  list.print();
  std::cout << std::endl;

  list.erase(21);
  std::cout << "List after deleting 21: ";
  list.print();
  std::cout << std::endl;

  list.insert(10);
  std::cout << "List after inserting 10: ";
  list.print();
  std::cout << std::endl;

  list.insert(44);
  std::cout << "List after inserting 44: ";
  list.print();
  std::cout << std::endl;

  list.insert(12);
  std::cout << "List after inserting 12: ";
  list.print();
  std::cout << std::endl;

  list.erase(8);
  std::cout << "List after deleting 8: ";
  list.print();
  std::cout << std::endl;

  // Test erasing the first element
  list.erase(17);
  std::cout << "List after deleting 17: ";
  list.print();
  std::cout << std::endl << std::endl;;

  // Test find
  
  std::cout << "find method should return pointer to that integer in the list.\n";
  int * whereIs37 = list.find(37);
  std::cout << "Memory address of 37: " << whereIs37 << std::endl;
  // This should be equal to 37
  std::cout << "Integer value at address " << whereIs37 << ": " << *whereIs37 << std::endl;

  std::cout << std::endl;

  return 0;
}
