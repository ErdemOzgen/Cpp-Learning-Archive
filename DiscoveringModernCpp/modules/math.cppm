// Example program for Discovering Modern C++
//
// File: math.cppm
// Date: 2020-02-03

export module math;

export import math.extra;

namespace math {

    export bool is_prime(long i);
    
           auto square(auto x) { return x * x; }    
    export auto cubic(auto x) { return square(x) * x; }
    
// is fortunately local now
#define MACRO_SQUARE(x) ((x) * (x))
        
} // namespace math


