// Example program for Discovering Modern C++
//
// File: constinit_example.cpp
// Date: 2020-02-13

#include <iostream>

using namespace std;

namespace dmc {
    
    const char *g() { return "dynamic initialization"; }
    constexpr const char *f(bool p) { return p ? "constant initializer" : g(); }

    constinit const char* c = f(true); // OK.
    // constinit const char* d = f(false); // ill-formed
    
    constexpr const char* e1= f(true);
    // constexpr const char* e2= f(false);
    
    constexpr long fibonacci(long n)
    {
        return n <= 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    constexpr long fibo8= fibonacci(8);
    
    constinit long global= fibo8; // doesn't compile with constinit
    
    struct stuff
    {
        stuff(long init) : value{init + shared} {}
        
        static long shared;
        long value;
    };
    
    struct hack
    {
        hack() { /*++fibo8;*/ /*++stuff::shared;*/ }
        
    };
    
    hack hacking;
    
    // long stuff::shared= fibo8; // value depends on initialization order
    // constinit long stuff::shared= fibo8; // initialization cannot be evaluated at compile time
    constinit long stuff::shared= fibonacci(8); // init at compile-time -> independent on init order
    
    hack hacking2;

    stuff s1{4}; // stuff::shared is guaranteed to be initialized
    
    // long stuff::shared= fibo8;
    

} // namespace dmc

int main()
{
    using namespace dmc;

    const char text[]= "Text";
    c= text;
    
    // e1= text; // error: read only
    
    cout << "fibo8 = " << fibo8 << endl;
    cout << "global = " << global << endl;
    cout << "s1.value = " << s1.value << endl;
    
    return 0;
}
