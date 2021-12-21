#include "Heap.hpp"

using namespace std;

int main() {
  class IsLess {
  public:
    bool operator()(const int& p, const int& q) {
      return p < q;
    }
  };

  HeapPriorityQueue<int, IsLess> HPL;
}
