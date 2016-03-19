#ifndef __LEFTIST_HEAP_H__
#define __LEFTIST_HEAP_H__

class LeftistNode {
 public:
  LeftistNode(int x);
  ~LeftistNode();
  void preorder();
  void inorder();
  void levelorder();
 private:
  int value;
  int rank;
  LeftistNode * right;
  LeftistNode * left;

  friend class MinLeftistHeap;
};

class MinLeftistHeap {
 public:
  MinLeftistHeap();
  ~MinLeftistHeap();
  void insert(int x);
  int deletemin();
  void preorder();
  void inorder();
  void levelorder();
 private:
  LeftistNode * root;
  LeftistNode* concatenate(LeftistNode * a, LeftistNode * b);
};

#endif
