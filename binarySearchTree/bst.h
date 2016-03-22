#ifndef __BST_H__
#define __BST_H__

#include <iostream>

class BST;

class Node {
 public:
  Node(int x);
  ~Node();
  void insert(int x);
  void remove(int x);
  int* search(int x);
  int deletemin();
  int deletemax();
  void preorder();
  void postorder();
  void inorder();
  void levelorder();
  void print();
 private:
  int value;
  Node * left;
  Node * right;

  friend class BST;
};

class BST {
 public:
  BST();
  ~BST();
  void insert(int x);
  void remove(int x);
  int* search(int x);
  int deletemin();
  int deletemax();
  void preorder();
  void inorder();
  void postorder();
  void levelorder();
  friend std::istream& operator>>(std::istream& in, BST& bst);
 private:
  Node * root;
};

#endif
