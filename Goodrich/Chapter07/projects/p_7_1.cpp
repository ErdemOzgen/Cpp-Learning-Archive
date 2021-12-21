#ifndef P_7_1_HPP
#define P_7_1_HPP

#include "tree.hpp"

typedef LinkedBinaryTree<int> Tree;

// Rotate methods

void rotateLeft(Tree t, Tree::Position p) {
  if (p.isRoot()) {
    return;
  }

  // Tree::Position temp = p;
  p.parent().right() = p.left();
  p.left() = p.parent();
  if (!p.parent().isRoot())
    p.parent() = p.left().parent();
  else {
    t.root() = p;
  }
  //p.left() = p.parent();
  //p.parent() = p.parent().parent();
}


#endif


#include <iostream>

using namespace std;


int main() {
  // Test if tree works:
  Tree lbt;
  cout << lbt.empty() << endl;
  lbt.addRoot();
  cout << lbt.empty() << endl;
  cout << lbt.size() << endl;
  lbt.expandExternal(lbt.root());
  cout << lbt.empty() << endl;
  cout << lbt.size() << endl;

  // rotateLeft(lbt.root().right());
  *(lbt.root()) = 12;
  *(lbt.root().left()) = 11;
  *(lbt.root().right()) = 13;
  cout << lbt;
  rotateLeft(lbt, lbt.root().right());
  cout << lbt;
}
