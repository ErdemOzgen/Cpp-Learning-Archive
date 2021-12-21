
#include <iostream>
#include "BinarySearchTree.hpp"

using namespace std;

int main() {
  BinarySearchTree< Entry<int,int> > t = BinarySearchTree< Entry<int,int> >();
  cout << t.size() << endl;
  t.insert(1, 10);
}
