#ifndef __SKEW_HEAP_H__
#define __SKEW_HEAP_H__

class SkewNode {
 public:
  SkewNode(int x);
  ~SkewNode();
  void preorder();
  void inorder();
  void levelorder();
  void print();
 private:
  int value;
  SkewNode * right;
  SkewNode * left;

  friend class MinSkewHeap;
};

class MinSkewHeap {
 public:
  MinSkewHeap();
  ~MinSkewHeap();
  void insert(int x);
  int deletemin();
  void preorder();
  void inorder();
  void levelorder();
 private:
  SkewNode * root;
  SkewNode* concatenate(SkewNode * a, SkewNode * b);
};

#endif
