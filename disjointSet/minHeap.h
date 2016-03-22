#ifndef __HEAP__
#define __HEAP__

class Line {
 public:
  Line();
  Line(int startPoint, int endPoint, int newLength);
  int start, end, length;

  friend std::ostream& operator<<(std::ostream &os, Line &line);
};

class MinHeap {
 public:
  MinHeap(Line buildArray[], int length);
  ~MinHeap();
  Line deletemin();
  bool isEmpty();
 private:
  Line* heap;
  int keyCount;
  int getParent(int index);
  void heapify(Line line, int index);
  Line removeAtIndex(int index);

  friend std::ostream& operator<<(std::ostream &os, MinHeap &heap);
};

#endif
