#include "PriorityQueue.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

class IsLess {
public:
  bool operator()(const int& p, const int& q) {
    return p < q;
  }
};

int main() {
  ListPriorityQueue<int, IsLess> L;
  try {
    cout << L.min();
  } catch (std::exception& e) {
    cout << "Exception found: " << e.what() << endl;
  }
}
