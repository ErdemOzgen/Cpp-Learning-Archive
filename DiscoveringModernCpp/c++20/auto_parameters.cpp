// Example program for Discovering Modern C++
//
// File: auto_parameters.cpp
// Date: 2020-02-24

#include <iostream>

using namespace std;

namespace dmc
{
    
    auto max(auto a, auto b)
    {
        return a > b ? a : b;        
    }

} // namespace dmc

int main()
{
    using namespace dmc;
    
    cout << "max(3, 7) = " << dmc::max(3, 7) << endl;
    cout << "max(3, 7.1) = " << dmc::max(3, 7.1) << endl;

    return 0;
}
