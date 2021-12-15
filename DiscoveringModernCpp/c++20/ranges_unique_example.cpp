// Example program for Discovering Modern C++
//
// File: range_unique_example.cpp
// Date: 2020-02-12

#include <iostream>
#include <vector>
#include <iterator>

#ifdef DMC2_WITH_NIEBLER
#  include <range/v3/range/conversion.hpp>
#  include <range/v3/algorithm.hpp>
#  include <range/v3/view/all.hpp>
#  include <range/v3/view/unique.hpp>
#  include <range/v3/view/common.hpp>
#  include <range/v3/view/enumerate.hpp>
#endif

using namespace std;

#ifdef DMC2_WITH_NIEBLER
namespace dmc {

    using namespace ::ranges;
        
    template <random_access_range Range>
    void sort(Range& r)
    {
        ::ranges::common_view common{r};
        sort(std::begin(r), std::end(r));        
    }
    
    
} // namespace dmc
#endif

int main()
{
#ifdef DMC2_WITH_NIEBLER
    using namespace dmc;
    
    vector<int> seq= {3, 4, 7, 9, 2, 5, 7, 8, 3, 4, 3, 9};    
    cout << "Seq = " << (seq | view::all) << endl; // easier to print as range
    
    ::ranges::sort(seq);    
    // cout << "Sorted: " << ::ranges::cpp20::all_view<vector<int>>{seq} << endl; 
    
    cout << "Sorted: " << view::all(seq) << endl; 
    
    cout << "Sorted: " << (seq | view::all) << endl; 
    
    cout << "Unique: " << view::unique(seq) << endl;
    
    // cout << "Enumerated: " << (seq | view::unique | view::enumerate) << endl; Compiler error in g++-10 !!!
    
    auto unique= seq | view::unique | to<vector<int>>;
    cout << "Unique vector: " << (unique | view::all) << endl;
    
    
#else
    cerr << "The example requires Niebler's ranges (by the time of writing)\n";
#endif

    return 0;
}
