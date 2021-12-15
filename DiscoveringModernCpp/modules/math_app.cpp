// Example program for Discovering Modern C++
//
// File: math_user.cpp
// Date: 2020-02-03

#include <iostream>

import math;

using namespace std;

int main()
{
    using namespace math;
    
    cout << "982'451'653 is " << (is_prime(982'451'653) ? "" : "not ") << "a prime number.\n";    
    
    // Error: max_check not exported
    // cout << "max_check(982'451'653) is " << max_check(982'451'653) << "\n";
    
    // Error: square not exported
    // cout << "3.7^2 = " << square(3.7) << endl;
    
    cout << "3.7^3 = " << cubic(3.7) << endl;
    
    // cout << "3.7^2 = " << MACRO_SQUARE(3.7) << endl;
    
    cout << "twice(0.7) = " << twice(0.7) << endl;
    
    return 0;
}
