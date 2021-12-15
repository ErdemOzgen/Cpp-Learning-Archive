
#include <iostream>
#include "print_compiler.hpp"

using namespace std;

struct nostack
{
    void operator delete(void* ptr) { cout << "delete\n"; free(ptr); }
    ~nostack() = delete;
};


int main (int argc, char* argv[]) 
{
    print_compiler();

    // nostack s1;

    nostack* s2= new nostack;

    // delete s2; // Doesn't compile: would call deleted destructor
    
    return 0;
}

