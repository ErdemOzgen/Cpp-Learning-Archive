#include <iostream>
#include "Vector.hpp"

int main() {
  std::vector<std::string> V;
  V.push_back ("Alice");
  V.push_back ("Bob");
  V.push_back ("Connor");
  std::cout << V << std::endl;
  reverse(V);
  std::cout << V << std::endl;
}
