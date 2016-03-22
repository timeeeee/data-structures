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
  void insert(int x);
  bool erase(int x);
  void print();
  int* find(int x);

  // LinkedList member methods need to be able to access value and next of nodes
  // so that the first node can be removed if its value is erased.
  friend class LinkedList;
};

#endif
