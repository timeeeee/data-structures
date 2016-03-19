#ifndef __DISJOINT_SET__
#define __DISJOINT_SET__

#include <iostream>
class DisjointSet;

class Node {
 public:
  Node();
  Node* getParent();
 private:
  int rank;
  Node* parent;

  friend class DisjointSet;
};

class DisjointSet {
 public:
  DisjointSet(int items);
  ~DisjointSet();
  bool join(int item1, int item2);
  Node* find(int item);
  bool areConnected(int item1, int item2);
 private:
  int size;
  Node* set;

  friend std::ostream& operator<<(std::ostream &os, DisjointSet &dSet);
};

#endif
