#include <iostream>
#include "Vector.hpp"

int main() {
  ArrayVector<int> A;
  std::cout << A.size() << std::endl;
  A.insert(0, 1);
  std::cout << A.at(0) << std::endl;
}
