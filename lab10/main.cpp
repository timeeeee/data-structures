#include <iostream>
#include <fstream>
#include "bQueue.h"

int main() {
  BQueue queue;

  std::ifstream infile("data.txt");
  int value;
  while (infile >> value) {
    queue.insert(value);
  }
  infile.close();

  int input = 0;
  while (input != 4) {
    input = 0;
    while (input < 1 || input > 4) {
      std::cout << "Please enter a command: \n";
      std::cout << "1: insert\n";
      std::cout << "2: deletemin\n";
      std::cout << "3: levelorder\n";
      std::cout << "4: exit\n\n";
      std::cout << "command: ";
      std::cin >> input;
      if (!std::cin) {
	std::cin.clear();
	std::cin.ignore(256, '\n');
      }
    }

    std::cout << std::endl;

    int value;
    switch (input) {
    case 1:
      std::cout << "Enter a value to insert: ";
      std::cin >> value;
      queue.insert(value);
      break;
    case 2:
      std::cout << "deletemin: \n" << queue.deletemin() << std::endl;
      break;
    case 3:
      std::cout << "levelorder: \n";
      queue.levelorder();
      std::cout << std::endl;
      break;
    }

    std::cout << std::endl;
  }

  return 0;
}
