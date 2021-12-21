#include <iostream>

// #include "linkedTree.hpp"
// #include "Position.hpp"
#include "treeGeneric.hpp"

using namespace std;

int main() {
  /*
  Position<int> p(5);
  cout << *p << endl;
  *p = 3;
  cout << *p << endl;

  Position<int> r(&p, 2);
  cout << *r <<endl;
  */
  LinkedBinaryTree<int> lbt;
  cout << lbt.empty() << endl;
  // lbt.expandExternal(lbt.root());
  cout << lbt.empty() << endl;

  lbt.addRoot();

  lbt.expandExternal(lbt.root());
  cout << lbt.empty() << endl;
  cout << lbt.size() << endl;

  try {
    lbt.expandExternal(lbt.root());
    cout << lbt.empty() << endl;
    cout << lbt.size() << endl;
  } catch (RuntimeException e) {
    cout << e.getMessage() << endl;
    // cout << "Error\n";
  }

  cout << "root->right is external: " << lbt.root().right().isExternal() << endl;
  try {
    lbt.expandExternal(lbt.root().right());
  } catch (RuntimeException e) {
    cout << e.getMessage() << endl;
  }

  try {
    lbt.removeAboveExternal(lbt.root().left());
  } catch (RuntimeException e) {
    cout << e.getMessage() << endl;
  }
  cout << lbt.empty() << endl;
  cout << lbt.size() << endl;

  LinkedBinaryTree<int>::PositionList pl;
  pl = lbt.positions();



  VectorBinaryTree<int> vbt;
  vbt.root();
}
