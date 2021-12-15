// Example program for Discovering Modern C++
//
// File: const_eval_example.cpp
// Date: 2020-02-13

#include <iostream>

using namespace std;

namespace dmc
{
    consteval long fibonacci(long n)
    {
        return n <= 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    
} // namespace dmc

int main()
{
    using namespace dmc;
    
    constexpr long fibo8= fibonacci(8);
    long var= 9;
    // fibonacci(var); // cannot be called with variable
    
    fibonacci(fibo8);

    return 0;
}
