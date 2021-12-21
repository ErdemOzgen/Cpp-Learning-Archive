#include <iostream>
#include "HashFunction.hpp"

using namespace std;


int main() {
  for (int i = 0; i < 1024; i++) {
    cout << i << ": " << (hashCode<int>(i) >> 16) << endl;
  }
}
