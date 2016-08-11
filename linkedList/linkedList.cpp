#include "linkedList.h"

#include <iostream>

#include "node.h"

// Initialize an empty list
LinkedList::LinkedList()
{
  firstNode = NULL;
}

// Delete first node (node destructor takes care of other nodes)
LinkedList::~LinkedList()
{
  if (firstNode) delete firstNode;
}

// Insert value into list
void LinkedList::insert(int x)
{
  if (firstNode)
    {
      firstNode->insert(x);
    }
  else
    {
      firstNode = new Node(x);
    }
}

bool LinkedList::isEmpty()
{
  return (firstNode == NULL);
}

// Delete integer from list. Return whether or not the number was in the list.
bool LinkedList::erase(int x)
{
  if (!firstNode) return false;
  // If x is first element in list, get new firstNode pointer
  if (firstNode->value == x)
    {
      Node* newFirst = firstNode->next;
      firstNode->next = NULL;
      delete firstNode;
      firstNode = newFirst;
      return true;
    }
  else
    {
      return firstNode->erase(x);
    }
}

// Print list
void LinkedList::print()
{
  if (firstNode) {
    firstNode->print();
    std::cout << "\n";
  } else {
    std::cout << "List is empty.\n";
  }
}

// Get first value in the list
int LinkedList::head()
{
  if (firstNode == NULL) return -1;
  return firstNode->value;
}

// Get pointer to where an integer is in the list. If not in the list, return
// null pointer.
int* LinkedList::find(int x)
{
  if (firstNode == NULL) return NULL;
  return firstNode->find(x);
}

// Read a value from a stream
std::istream& operator>>(std::istream &in, LinkedList &list)
{
  int value = 0;
  in >> value;
  list.insert(value);
  return in;
}
