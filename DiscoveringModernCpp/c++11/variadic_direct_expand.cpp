#include <iostream>
#include "../c++11/print_compiler.hpp"

using namespace std;

#if 0
template <typename ...Args>
void print1(ostream& os, const Args& ...args) 
{
    (os << args << ", ")...; 
    os << '\n';
}
#endif 
template <typename ...Args>
void dummy(Args ...) {}

#if 0
template <typename ...Args>
void print2(ostream& os, const Args& ...args) 
{
    dummy((os << args << ", ")...); 
    os << '\n';
}
#endif 

template <typename ...Args>
void print3(ostream& os, const Args& ...args) 
{
    dummy((os << args << ", ",  0)...); 
    os << '\n';
}
 
template <typename ...Args>
void print4(ostream& os, const Args& ...args) 
{ 
    // auto dummy [[maybe_unused]] = {(os << args << ", ",  0)...}; 
    auto dummy= {(os << args << ", ",  0)...};
    os << '\n';
}


int main (int argc, char* argv[]) 
{
    print_compiler();

    // print1(cout, 3, 17.2, "Thingy");
    // print2(cout, 3, 17.2, "Thingy");
    print3(cout, 3, 17.2, "Thingy");
    print4(cout, 3, 17.2, "Thingy");

    return 0;
}

