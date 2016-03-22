#ifndef __QUEUE_H__
#define __QUEUE_H__

class Node {
 public:
  Node(int newValue);
  Node();
  ~Node();
 private:
  int key;
  int order;
  Node* firstChild;
  Node* rightSibling;
  Node* leftSibling;

  friend class BQueue;
};

class BQueue {
 public:
  BQueue();
  ~BQueue();
  void insert(int value);
  int deletemin();
  void merge(Node* otherQueue);
  void levelorder();
 private:
  Node* root;
};

#endif
