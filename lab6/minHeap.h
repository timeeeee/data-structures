#ifndef __HEAP_H__
#define __HEAP_H__

class MinHeap {
 public:
  MinHeap(int treeK);
  void build(int buildArray[], int buildLength);
  void insert(int x);
  int deletemin();
  int deletemax();
  void remove(int x);
  void levelorder();

 private:
  int heap[500];
  int keyCount;
  int k;
  void heapify(int n, int index);
  int getParent(int index);
  int removeAtIndex(int index);
};

#endif
