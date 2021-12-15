// Example program for Discovering Modern C++
//
// File: range_filter_example.cpp
// Date: 2020-02-12

#include <iostream>
#include <list>

#ifdef DMC2_WITH_NIEBLER
#  include <range/v3/range/conversion.hpp>
#  include <range/v3/view/filter.hpp>
#endif

using namespace std;

namespace dmc {

    using namespace ::ranges;
    
    bool in_range(int i) { return i > 4 && i < 7; }

    
    
} // namespace dmc

int main()
{
    using namespace dmc;
    
    list<int> seq= {3, 4, 7, 6, 9, 2, 5, 7, 8};
    
    cout << "Entries in range are: " << (seq | view::filter(in_range)) << '\n';

    auto seqf= seq | view::filter(in_range) | to<list<int>>;
    
    return 0;
}
