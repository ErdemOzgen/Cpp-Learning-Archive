#include <iostream>
#include "../c++11/print_compiler.hpp"

using namespace std;



int main (int argc, char* argv[]) 
{
    print_compiler();
 
    int x= 5, y= 6, z, op_code= 2;
    
    switch(op_code) {
      case 0: z= x + y; break;
      case 1: z= x - y; cout << "compute diff\n"; break;
      case 2: x= y; // [[fallthrough]];
      case 3: z= x * y; break;
      default: z= x / y;
    }

    cout << "x op y = " << z << endl;
 
    return 0; 
}
 
 
