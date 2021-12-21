#include <iostream>

#include "Deque.hpp"

int main() {
  LinkedDeque <int> LD;
  LD.insertFront(5);
  LD.insertFront(6);
  LD.insertFront(7);
  LD.insertFront(8);
  std::cout << LD << std::endl;
}
