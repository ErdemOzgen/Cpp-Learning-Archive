#include <iostream>
#include "SLinkedList.hpp"

using namespace std;

int main () {
  SLinkedList <int> SL;
  SL.addFront(5);
  cout << SL << endl;
  SL.addFront(6);
  cout << SL << endl;
  SL.removeFront();
  cout << SL << endl;
  SL.removeFront();
  cout << SL << endl;
  SL.removeFront();
  cout << SL << endl;
  SL.removeFront();
  cout << SL << endl;
  
}
