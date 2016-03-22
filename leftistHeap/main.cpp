#include <iostream>
#include <fstream>
#include "heap.h"

int main() {
  MinLeftistHeap heap;

  std::ifstream infile("data.txt");
  int insertValue;
  while (infile >> insertValue) {
    std::cout << "about to insert " << insertValue << " ... " << std::flush;
    heap.insert(insertValue);
    std::cout << " done.\n";
  }
  infile.close();

  int input = 0;
  while (input != 6) {
    input = 0;
    while (input < 1 || input > 6) {
      std::cout << "Please enter a command: \n";
      std::cout << "1: insert\n";
      std::cout << "2: deletemin\n";
      std::cout << "3: preorder\n";
      std::cout << "4: inorder\n";
      std::cout << "5: levelorder\n";
      std::cout << "6: exit\n\n";
      std::cout << "command: ";
      std::cin >> input;
      if (!std::cin) {
	std::cin.clear();
	std::cin.ignore(256, '\n');
      }
    }

    std::cout << std::endl;

    int value = 0;
    switch (input) {
    case 1:
      std::cout << "Enter a value to insert: ";
      std::cin >> value;
      heap.insert(value);
      break;
    case 2:
      std::cout << "deletemin: \n" << heap.deletemin() << std::endl;
      break;
    case 3:
      std::cout << "preorder: ";
      heap.preorder();
      std::cout << std::endl;
      break;
    case 4:
      std::cout << "inorder: ";
      heap.inorder();
      std::cout << std::endl;
      break;
    case 5:
      std::cout << "levelorder: \n";
      heap.levelorder();
      std::cout << std::endl;
      break;
    }

    std::cout << std::endl;
  }

  return 0;
}
