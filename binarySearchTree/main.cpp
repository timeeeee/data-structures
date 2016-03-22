#include <iostream>
#include <fstream>
#include "bst.h"
#include "queue.h"

int main() {
  BST bst;
  std::ifstream infile("data.txt");
  infile >> bst;

  int input = 0;
  while (input != 8) {
    input = 0;
    while (input < 1 || input > 8) {
      std::cout << "Please enter a command: \n";
      std::cout << "1: insert\n";
      std::cout << "2: remove\n";
      std::cout << "3: deletemin\n";
      std::cout << "4: deletemax\n";
      std::cout << "5: preorder\n";
      std::cout << "6: inorder\n";
      std::cout << "7: levelorder\n";
      std::cout << "8: exit\n\n";
      std::cout << "command: ";
      std::cin >> input;
      if (!std::cin) {
	std::cin.clear();
	std::cin.ignore(256, '\n');
      }
    }

    int value = 0;
    switch (input) {
    case 1:
      std::cout << "Enter a value to insert: ";
      std::cin >> value;
      bst.insert(value);
      break;
    case 2:
      std::cout << "Enter a value to remove: ";
      std::cin >> value;
      bst.remove(value);
      break;
    case 3:
      std::cout << "deletemin: " << bst.deletemin() << std::endl;
      break;
    case 4:
      std::cout << "deletemax: " << bst.deletemax() << std::endl;
      break;
    case 5:
      std::cout << "preorder: ";
      bst.preorder();
      std::cout << std::endl;
      break;
    case 6:
      std::cout << "inorder: ";
      bst.inorder();
      std::cout << std::endl;
      break;
    case 7:
      std::cout << "levelorder: ";
      bst.levelorder();
      std::cout << std::endl;
      break;
    }
  }

  return 0;
}
