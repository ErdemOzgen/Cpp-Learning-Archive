#ifndef NSP_H
#define NSP_H

#include <iostream>

namespace MyNamespace {

  class Print {
  public:
    Print(int times=3) {
      while(times!=0) {
        std::cout << "Hello from class Print -> namespace MyNamespace!\n";
        times--;
      }
    }
    ~Print() {}
  };

}

#endif /* nsp.hpp */
