#ifndef __HEAP_H__
#define __HEAP_H__

class MinMaxHeap {
 public:
  MinMaxHeap();
  void build(int buildArray[], int buildLength);
  void insert(int x);
  int deletemin();
  int deletemax();
  void levelorder();

 private:
  int heap[500];
  int keyCount;
  void trickleDown(int index);
  void trickleDownMin(int index);
  void trickleDownMax(int index);
  void bubbleUp(int index);
  void bubbleUpMin(int index);
  void bubbleUpMax(int index);
  int getParent(int index);
  bool isMinRow(int index);
  int removeAtIndex(int index);
};

#endif
