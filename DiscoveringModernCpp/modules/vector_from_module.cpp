// Example program for Discovering Modern C++
//
// File: vector_from_module.cpp
// Date: 2020-02-03

// import <iostream>
// import std.core;

#include <iostream> 

import vector;


// using namespace std;
// 
// namespace dmc
// {
// 
// } // namespace dmc

int main()
{
    using namespace dmc; 

    dmc::vector<double> v{3, 2, 1}, w{2, 3, 4}, u{4, 3, 2};
//     std::cout << "u is " << u << std::endl;
//     v= {7, 8, 9};
//     std::cout << "v is " << v << std::endl;
// 
//     vector x{std::move(w)}, y{x};
//     std::cout << "x is " << x << std::endl;
//     std::cout << "w is " << w << std::endl;
// 
//     v= std::move(u);
//     std::cout << "v is " << v << std::endl;
//     std::cout << "u is " << u << std::endl;
// 
//     std::cout << "x + y is " << x + y << std::endl;
    
    return 0;
}
