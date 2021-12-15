#include <iostream>
#include <tuple>
#include <utility>
#include <string>

#include "../c++11/print_compiler.hpp"

using namespace std;

struct printer {
    template <typename First, typename ...Rest>
    void operator()(const First& f, const Rest& ...r) const {
	    if constexpr(sizeof...(r) == 0) {
	        cout << f << '\n';
	    } else {
	        cout << f << ", "; (*this)(r...);
	    }
    }
};

template <typename ...Args>  
struct caller 
{
    caller(Args&& ...args) : t(forward<Args>(args)...) {}

    template <typename F> auto call(F f) const
    {  call_help(f, make_index_sequence<sizeof...(Args)>{}); }

    template <typename F, size_t ...I>
    auto call_help(F f, index_sequence<I...>) const
    {  return f(get<I>(t)...); }

    // template <typename F> auto call(F f) const
    // {  std::apply(f, t); }
    
    std::tuple<Args...> t;
};




int main (int argc, char* argv[]) 
{
    print_compiler();

    caller<int, double, string> data(3, 17.2, "Thingy"s); // template types still needed in VS
    data.call(printer{});

    return 0;
}

