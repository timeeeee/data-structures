#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "heap.h"

class Queue;

class Bucket {
 public:
  Bucket(LeftistNode* node);
 private:
  LeftistNode* value;
  Bucket * next;

  friend class Queue;
};

class Queue {
 public:
  Queue();
  ~Queue();
  void enqueue(LeftistNode* node);
  LeftistNode* dequeue();
  void print();
  bool empty();
 private:
  // Buckets are added at back, popped off front
  Bucket * first;
  Bucket * last;
};

#endif
