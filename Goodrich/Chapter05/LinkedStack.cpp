#include <iostream>
#include "Stack.hpp"

int main() {
  LinkedStack<int> LS;
  LS.push(3);
  LS.push(1);
  LS.push(17);
  std::cout << LS << std::endl;
  LS.pop();
  std::cout << LS << std::endl;
}
