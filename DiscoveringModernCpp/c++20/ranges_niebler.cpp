// Example program for Discovering Modern C++
//
// File: ranges_niebler.cpp
// Date: 2020-01-30

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
#  include <range/v3/view/reverse.hpp>
#  include <range/v3/view/all.hpp>
#  include <range/v3/view/join.hpp>
#endif

using namespace std;

namespace dmc
{

} // namespace dmc

int main()
{
    using namespace dmc;
    
#ifdef DMC2_WITH_NIEBLER

    using namespace ::ranges;
    
    vector<int> numbers{3, 9, 2, 8, 4};
    ostream_iterator<int> osi{cout, ", "};
    
//     ::ranges::sort(numbers);    
//     std::copy(std::begin(numbers), std::end(numbers), osi); cout << endl;
    
    auto is_even= [](int n){ return n % 2 == 0; };
    auto square= [](int n){ return n * n; };
    
    // auto even_numbers= ::ranges::view::filter(numbers, [](int n){ return n % 2 == 0; });
    auto even_numbers= numbers | view::filter(is_even)
                               | view::transform(square);
                               
    // deprecated, should use conversion.hpp                           
//     vector<int> even_number_pairs= numbers | view::filter(is_even)
//                                            | view::transform(square); 
                               
    // better like this:
    auto even_number_converted= ::ranges::to<vector<int>>(numbers | view::filter(is_even));
                               
    // ambiguous without std::
    std::copy(std::begin(even_numbers), std::end(even_numbers), osi); cout << endl;
    // copy(even_numbers, osi); cout << endl; // ambiguous
    // ::ranges::copy(even_numbers, osi); cout << endl; // not found
    // copy(even_number_pairs, osi); cout << endl;  // ambiguous
    // ::ranges::copy(even_number_pairs, osi); cout << endl;  // not found
    
//     ::ranges::filter_view<vector<int>, decltype(is_even)> fv{numbers, is_even};
//     for (int i : fv)
//         cout << i << endl;
    
//     for (int i : filter_view{numbers, is_even})
//         cout << i << endl;
    
    for (int i : view::filter(numbers, is_even))
        cout << i << endl;
    
//     for (int i : transform_view{filter_view{numbers, is_even}, square})
//         cout << i << endl;
    
    for (int i : view::transform(view::filter(numbers, is_even), square))
        cout << i << endl;
    
    for (int i : numbers | view::filter(is_even) | view::transform(square))
        cout << i << endl;
    
//     for (int i : numbers | ::ranges::sort | view::filter(is_even) | view::transform(square))
//         cout << i << endl;
    
    std::pair<int, std::string_view> pairs[] = {{2, "foo"}, {1, "bar"}, {0, "baz"}}, 
                                     more_pairs[] = {{3, "ding"}, {4, "bums"}, {1, "bar"}};
    // sort ints only, projection 15.3.18
    ::ranges::sort(pairs, ::ranges::less{}, [](auto const& p) { return p.first; });  
    ::ranges::sort(pairs, ::ranges::less{}); // sort pairs
    
    // less is a class template in std and a class with a template operator() in range
    ::ranges::sort(pairs, std::less<int>{}, [](auto const& p) { return p.first; });  
    for (auto [num, sv] : pairs)
        cout << num << ": " << sv << endl;
    
    for (auto [num, sv] : pairs | view::reverse)
        cout << num << ": " << sv << endl;
    
    vector<string> ss{"hello", " ", "world", "!"};
    cout << "Type of joined ss = " << typeid(ss | view::join).name() << '\n';
    cout << "joined ss = " << (ss | view::join) << endl;
    // string s= ss | view::join; // deprecated, should use conversion.hpp
    string s= ::ranges::to<string>(ss | view::join); 
    cout << "String is " << s << endl;
    
#else    
    cout << "ranges_niebler: Eric Niebler's library is not enabled.\n";
#endif
    

    return 0;
}
