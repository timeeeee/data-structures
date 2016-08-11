#include "node.h"

#include <iostream>

// Create new node with value x, and next pointer is null
Node::Node(int x)
{
  value = x;
  next = NULL;
}
 
// Recursively delete all following nodes
Node::~Node()
{
  // Call delete to recurse through rest of list
  if (next) delete next;
}

// Insert new value (new node if next is null, otherwise recurse)
void Node::insert(int x)
{
  if (value != x) {
    if (next) {
      next->insert(x);
    } else {
      next = new Node(x);
    }
  }
}

// If the _next_ node has value x, remove it and reconnect the list
bool Node::erase(int x)
{
  // If this is the last item, return false
  if (!next) return false;

  // If next item is x, delete that node and point to new next node
  if (next->value == x)
    {
      Node* newNext = next->next;
      next->next = NULL;
      delete next;
      next = newNext;
      return true;
    }
  else return next->erase(x);
}

// Print the value and " ", and recurse to next value
void Node::print()
{
  std::cout << value;
  if (next)
    {
      std::cout << " ";
      next->print();
    }
}

// Return pointer to the node with value x. If not in list, return null
int* Node::find(int x)
{
  if (value == x) return &value;
  if (!next) return NULL;
  return next->find(x);
}
