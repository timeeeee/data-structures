#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "heap.h"

class Queue;

class Bucket {
 public:
  Bucket(SkewNode* node);
 private:
  SkewNode* value;
  Bucket * next;

  friend class Queue;
};

class Queue {
 public:
  Queue();
  ~Queue();
  void enqueue(SkewNode* node);
  SkewNode* dequeue();
  void print();
  bool empty();
 private:
  // Buckets are added at back, popped off front
  Bucket * first;
  Bucket * last;
};

#endif
