// Example program for Discovering Modern C++
//
// File: concept_with_or.cpp
// Date: 2020-01-30

#include <iostream>
#include <type_traits>
#include <string>

using namespace std;

namespace dmc {
    
#if 0 // || with type traits
    template <typename T>
    concept arithmetic_intrinsic = std::is_floating_point_v<T> || std::is_integral_v<T>;
#endif
    
    // now we try || with concepts
    template <typename T>
    concept is_float= std::is_floating_point_v<T>;
    
    template <typename T>
    concept is_integral= std::is_integral_v<T>;
    
    template <typename T>
    concept arithmetic_intrinsic = is_float<T> || is_integral<T>;
    
    template <typename T>
    string ari_string= (arithmetic_intrinsic<T> ? "" : "not ");
    
} // namespace dmc

int main()
{
    using namespace dmc;
    
    cout << "int is " << ari_string<int> << "an arithmetic_intrinsic.\n";
    cout << "float is " << ari_string<float> << "an arithmetic_intrinsic.\n";
    
    struct dummy {};
    cout << "dummy is " << ari_string<dummy> << "an arithmetic_intrinsic.\n";

    return 0;
}
