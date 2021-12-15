#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include "../c++11/print_compiler.hpp"

using namespace std;

namespace dmc {

template <typename Container, typename Functor>
constexpr Container transform(const Container& c, Functor f)
{
    Container t{};
    for (unsigned i= 0; i < size(c); ++i) 
	t[i]= f(c[i]);
    return t;
}

    constexpr int inc_by_3(int i) { return i + 3; }
}

int main (int argc, char* argv[]) 
{
    print_compiler();

    constexpr array<int, 6> a{{3, 7, 2, 4, 5, 9}};

    constexpr auto daf= dmc::transform(a, dmc::inc_by_3);   
    copy(begin(daf), end(daf), ostream_iterator<int>(cout, ", "));
    cout << endl;
   
    // constexpr auto dal1= dmc::transform(a, [](int i){return i+3;});
    constexpr auto dal1= dmc::transform(a, [](int i) constexpr ->int {return i+3;});
    copy(begin(dal1), end(dal1), ostream_iterator<int>(cout, ", "));
    cout << endl;

    int inc= 3;
    constexpr int cinc= 3;
    // constexpr auto dal2= dmc::transform(a, [inc](int i){return i+inc;});
    // constexpr auto dal2= dmc::transform(a, [inc](int i) constexpr {return i+inc;});
    constexpr auto dal2= dmc::transform(a, [](int i) {return i+cinc;});
    copy(begin(dal2), end(dal2), ostream_iterator<int>(cout, ", "));
    cout << endl;

    constexpr auto l1= [](int i){return i+3;}; // Okay (comment to avoid warning for not using)
    // constexpr auto l2= [inc](int i){return i+inc;}; // Error: isn't constexpr
   
   
    auto l3= [](int i) {return i+3;};
    constexpr auto dal3= dmc::transform(a, l3);
    copy(begin(dal3), end(dal3), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    // auto l4= [inc](int i) {return i+inc;};
    // constexpr auto dal4= dmc::transform(a, l4);
    // copy(begin(dal4), end(dal4), ostream_iterator<int>(cout, ", "));
    // cout << endl;

    // Nonsense to avoid warning for not using variable (OMG)
    (void)inc; (void)l1;
    
    return 0;
}

