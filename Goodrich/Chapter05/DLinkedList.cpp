#include <iostream>
#include "DLinkedList.hpp"

int main() {
  DLinkedList<int> ll;
  ll.addFront(10);
  std::cout << ll << std::endl;
  ll.addFront(11);
  std::cout << ll << std::endl;
  ll.removeFront();
  std::cout << ll << std::endl;
  ll.removeFront();
  std::cout << ll << std::endl;  
  ll.removeFront();
  std::cout << ll << std::endl;

}
  
