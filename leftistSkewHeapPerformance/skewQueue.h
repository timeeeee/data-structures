#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "skewHeap.h"

class SkewQueue;

class Bucket {
 public:
  Bucket(SkewNode* node);
 private:
  SkewNode* value;
  Bucket * next;

  friend class SkewQueue;
};

class SkewQueue {
 public:
  SkewQueue();
  ~SkewQueue();
  void enqueue(SkewNode* node);
  SkewNode* dequeue();
  bool empty();
 private:
  // Buckets are added at back, popped off front
  Bucket * first;
  Bucket * last;
};

#endif
