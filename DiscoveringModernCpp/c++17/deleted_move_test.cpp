#include <iostream>
#include "../c++11/print_compiler.hpp"

using namespace std;

struct nomove
{
    nomove() { cout << "Default ctor.\n"; }
    nomove(const nomove&) { cout << "Copy ctor.\n"; }
    // nomove(nomove&&) = delete; // Impedes move op in all standards (C++11-17)
};


int main (int argc, char* argv[]) 
{
    print_compiler();
    nomove n1, n2(move(n1));

    return 0;
}

 
