#ifndef __LEFTIST_QUEUE_H__
#define __LEFTIST_QUEUE_H__

#include "leftistHeap.h"

class LeftistQueue;

class Bucket {
 public:
  Bucket(LeftistNode* node);
 private:
  LeftistNode* value;
  Bucket * next;

  friend class LeftistQueue;
};

class LeftistQueue {
 public:
  LeftistQueue();
  ~LeftistQueue();
  void enqueue(LeftistNode* node);
  LeftistNode* dequeue();
  bool empty();
 private:
  // Buckets are added at back, popped off front
  Bucket * first;
  Bucket * last;
};

#endif
