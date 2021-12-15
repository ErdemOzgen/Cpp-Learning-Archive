#include <iostream>
// #include "print_compiler.hpp"

using namespace std;

constexpr void square(int &x) { x *= x; }

constexpr int f(int x) { square(x); return x; }

int main (int argc, char* argv[]) 
{
    // print_compiler();

    constexpr int twosq= f(2);
    cout << "twosq = " << twosq << endl;

    return 0;
}

