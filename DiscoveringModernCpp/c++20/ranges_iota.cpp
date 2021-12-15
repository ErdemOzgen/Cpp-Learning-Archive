// Example program for Discovering Modern C++
//
// File: range_iota.cpp
// Date: 2020-02-12


#include <iostream>
#include <vector>

#if __has_include(<ranges>)
# include <ranges>
# define WITH_RANGES
#endif


int main()
{
    using namespace std;
    using namespace std::ranges;
    
#ifdef WITH_RANGES
    vector<int> v{3, 9, 2, 8, 4};
    
    std::cout << "Ranges exist in g++-10 but doesn't contain much.\n";
    
    for (int i : iota_view{1, 10})
        cout << i << endl;    
#else
    std::cout << "no ranges yet :-(\n";
#endif
}
