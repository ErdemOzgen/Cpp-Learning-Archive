
#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main() {
  // Basic syntax test:
  BinaryTree<int> t = BinaryTree<int>();
  cout << t.size() << endl;
  t.addRoot();
  cout << t.size() << endl;
  return 0;
}
