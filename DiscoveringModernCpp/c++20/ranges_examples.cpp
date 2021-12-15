// Example program for Discovering Modern C++
//
// File: ranges_examples.cpp
// Date: 2020-04-03

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string_view>
#include <string>
#include <typeinfo>

#ifdef DMC2_WITH_NIEBLER
#  include <range/v3/range.hpp>
#  include <range/v3/range/conversion.hpp>
#  include <range/v3/functional/comparisons.hpp>
#  include <range/v3/algorithm.hpp>
#  include <range/v3/algorithm/copy.hpp>
#  include <range/v3/view/filter.hpp>
#  include <range/v3/view/transform.hpp>
#  include <range/v3/view/unique.hpp>
#  include <range/v3/view/reverse.hpp>
#  include <range/v3/view/all.hpp>
#  include <range/v3/view/join.hpp>
#endif


using namespace std;

namespace dmc {

    bool in_range(int i) { return i > 4 && i < 7; }
    
} // namespace dmc

int main()
{
    using namespace dmc;
    
#ifdef DMC2_WITH_NIEBLER
    using namespace ::ranges;
    
    vector<int> seq= {3, 4, 7, 6, 9, 2, 5, 7, 8};
    
    for (int i : view::filter(seq, in_range))
        cout << i << " is in range.\n";
    cout << endl;

    auto square= [](int n){ return n * n; };

    for (int i : view::transform(view::filter(seq, in_range), square))
        cout << i << " is the squared value of an in-range entry.\n";
    cout << endl;
    
    for (int i : seq | view::filter(in_range) | view::transform(square))
        cout << i << " is the squared value of an in-range entry.\n";
    cout << endl;
    
    cout << "seq = " << view::all(seq) << endl << endl;
    
    vector<string> ss{"Discovering ", "Modern ", "C++"};
    cout << "joined:    " << view::join(ss) << endl;
    auto s= ss | view::join | to<string>;
    cout << "as string: " << s << endl << endl;
    
    vector<int> seq2= {3, 4, 7, 9, 2, 5, 7, 8, 3, 4, 3, 9};    
    cout << "seq2:          " << view::all(seq2) << endl; 
    
    ::ranges::sort(seq2);    
    cout << "sorted:        " << view::all(seq2) << endl;     
    
    auto unique= seq2 | view::unique | to<vector<int>>;
    cout << "unique vector: " << view::all(unique) << endl;

#else
    cerr << "The example requires Niebler's ranges (by the time of writing)\n";
#endif
    
    return 0;
}
