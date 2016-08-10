#include <iostream>
#include <fstream>
#include <cassert>

#include "linkedList.h"

int main()
{  
  // create and delete empty node
  {
    Node node(1);
    assert(node.tail());
  }

  // Add some numbers to a node, delete 'em
  {
    Node node(1);
    node.insert(2);
    assert(!node.tail());
    node.insert(3);
    node.erase(2);
    assert(node.find(1) != NULL);
    assert(node.find(2) == NULL);
    assert(node.find(3) != NULL);
    node.erase(3);
    assert(node.find(3) == NULL);
    assert(node.tail());
  }

  // is or is not empty
  {
    LinkedList list;
    assert(list.isEmpty());
    list.insert(1);
    assert(!list.isEmpty());
    list.erase(1);
    assert(list.isEmpty());
  }

  // read from file
  {
    std::ifstream infile;
    infile.open("data.txt");
    if (!infile) {
      std::cerr << "data.txt not found.\n";
      return 1;
    }

    LinkedList list;
    while (!infile.eof()) infile >> list;
    list.print();

    int numbers[100];
    int count = 0;
    infile.seekg(0);
    while (infile >> numbers[count]) count++;
    for (int i = 0; i < count; i++) std::cout << numbers[i] << " ";
    std::cout << "\n";
    infile.close();

    assert(!list.isEmpty());
    for (int i = 0; i < count; i++)
      {
	assert(list.head() == numbers[i]);
	list.erase(numbers[i]);
      }
  } // read from file scope

  // Test print
  LinkedList list;
  std::ifstream infile;
  infile.open("data.txt");
  while (infile) infile >> list;
  infile.close();
  std::cout << "List: ";
  list.print();
  std::cout << std::endl;

  // Test erase
  // Test erasing the first element
  // Test find

  std::cout << "All tests passed!\n";

  return 0;
}
