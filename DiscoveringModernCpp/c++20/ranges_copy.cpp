// Example program for Discovering Modern C++
//
// File: ranges_copy.cpp
// Date: 2020-03-20

#include <iostream>
#include <vector>

#ifdef DMC2_WITH_NIEBLER
#  include <range/v3/range/conversion.hpp>
#  include <range/v3/algorithm.hpp>
#  include <range/v3/view/all.hpp>
#  include <range/v3/view/unique.hpp>
#  include <range/v3/view/enumerate.hpp>
#endif

using namespace std;

#ifdef DMC2_WITH_NIEBLER
namespace dmc {

using namespace ::ranges;
    
template <typename R>
concept ResizableRange =
    range<R> &&
    requires(R& r, size_t n) 
    {
        r.resize(n);
    };
	
template <sized_range Source, ResizableRange Target> 
auto copy(const Source& src, Target& tgt)
{
    tgt.resize(::ranges::size(src));
    return ::ranges::copy(src, std::begin(tgt));
}
    
    
    
} // namespace dmc
#endif

int main()
{
#ifdef DMC2_WITH_NIEBLER
    using namespace dmc;
    using namespace ::ranges;
    
    vector<int> u{3, 2, 6, 7, 4}, v(5), w; 
    cout << "u = " << (u | view::all) << endl;
    
    ::ranges::copy(u, std::begin(v));
    cout << "v = " << (v | view::all) << endl;
    
    dmc::copy(u, w);
    cout << "w = " << (w | view::all) << endl;
    
#else
    cerr << "The example requires Niebler's ranges (by the time of writing)\n";
#endif
    
    
    return 0;
}
