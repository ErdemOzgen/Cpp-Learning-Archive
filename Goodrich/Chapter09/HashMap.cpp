#include <iostream>
#include "HashMap.hpp"

using namespace std;

int main() {
  HashMap<int,int,int> HM(10);
  HM.put(10, 1);
  HM.erase(10);
}


// This is another commit
