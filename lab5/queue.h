#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "bst.h"

class Queue;

class Bucket {
 public:
  Bucket(Node* node);
  void print();
 private:
  Node* value;
  Bucket * next;

  friend class Queue;
};

class Queue {
 public:
  Queue();
  ~Queue();
  void enqueue(Node* node);
  Node* dequeue();
  void print();
 private:
  // Buckets are added at back, popped off front
  Bucket * first;
  Bucket * last;
};

#endif
