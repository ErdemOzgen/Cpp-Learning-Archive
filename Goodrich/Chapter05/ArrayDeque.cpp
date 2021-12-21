#include <iostream>
#include "Deque.hpp"

int main() {
  ArrayDeque<int> AD(5);
  std::cout << AD << std::endl;

  AD.insertFront(5);
  AD.insertBack(3);
  std::cout << AD << std::endl;

  AD.insertFront(2);
  std::cout << AD << std::endl;

  AD.removeBack();
  AD.removeBack();
  std::cout << AD << std::endl;

  try {AD.removeBack();}
  catch (DequeEmpty& dee) {
    std::cout << "Caught 1: " << dee.getMessage() << std::endl;
  }
  try {AD.removeBack();}
  catch (DequeEmpty& dee) {
    std::cout << "Caught 2: " << dee.getMessage() << std::endl;
  }
  std::cout << AD << std::endl;

  int i;
  try {
    for (i = 0; i < 10; i++) {
      AD.insertFront(i);
      // AD.insertBack(2*i);
    } 
  } catch (DequeFull& dfe) {
    std::cout << "Caught " << i << ": " << dfe.getMessage() << std::endl;
    std::cout << AD << std::endl;
  }
}
