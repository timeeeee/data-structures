#include <iostream>
#include <fstream>
#include "minMaxHeap.h"

int main() {
  MinMaxHeap heap;

  std::ifstream infile("data.txt");
  int buildArray[500];
  int count = 0;
  while (infile >> buildArray[count]) {
    count ++;
  }
  infile.close();
  heap.build(buildArray, count);

  int input = 0;
  while (input != 5) {
    input = 0;
    while (input < 1 || input > 6) {
      std::cout << "Please enter a command: \n";
      std::cout << "1: insert\n";
      std::cout << "2: deletemin\n";
      std::cout << "3: deletemax\n";
      std::cout << "4: levelorder\n";
      std::cout << "5: exit\n\n";
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
      std::cout << "deletemax: \n" << heap.deletemax() << std::endl;
      break;
    case 4:
      std::cout << "levelorder: \n";
      heap.levelorder();
      std::cout << std::endl;
      break;
    }

    std::cout << std::endl;
  }

  return 0;
}
