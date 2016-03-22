#ifndef __NODE_H__
#define __NODE_H__

class Node {
 private:
  int value;
  Node* next;

 public:
  // Create new node with value x, and next pointer is null
  Node(int x);
  
  // Recursively delete all following nodes
  ~Node();
  
  // Insert new value (new node if next is null, otherwise recurse)
  void insert(int x);

  // If the _next_ node has value x, remove it and reconnect the list
  bool erase(int x);

  // Print the value and " ", and recurse to next value
  void print();

  // Return pointer to the node with value x. If not in list, return null
  int* find(int x);

  // LinkedList member methods need to be able to access value and next of nodes
  // so that the first node can be removed if its value is erased.
  friend class LinkedList;
};

#endif
