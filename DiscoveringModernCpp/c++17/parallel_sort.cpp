#include <cassert>
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <typeinfo>
#include <algorithm>

#if __has_include(<execution>)
    #define PARSTL 2
    #include <execution>
    #include <algorithm>
#elif __has_include(<experimental/execution>)
    #define PARSTL 1
    #include <experimental/execution>
    #include <experimental/algorithm>
#else
   #include <algorithm>
#endif


using namespace std::chrono;

template <typename TP>
double duration_ms(const TP& from, const TP& to)
{
    return duration_cast<nanoseconds>(to - from).count() / 1000.;
}


std::default_random_engine& global_urng()
{
    static std::default_random_engine u{};
    return u;
}

void randomize()
{
    static std::random_device rd{};
    global_urng().seed(rd());
}

int pick(int from, int thru)
{
    static std::uniform_int_distribution<> d{};
    using parm_t= decltype(d)::param_type;
    return d(global_urng(), parm_t{from, thru});
}


#ifdef PARSTL
template <typename Policy>
void sort_as(Policy&& p, std::vector<int>& v)
{
    auto start= steady_clock::now();
    sort(p, begin(v), end(v));
    auto end= steady_clock::now();
    std::cout << "Sorting with " << typeid(p).name() << " took "
	      << duration_ms(start, end) / 1e6 << "s.\n";
}
#endif


int main(int argc, char** argv)  
{
#ifdef PARSTL
    using namespace std::execution;
    unsigned s= 1000;
    if (argc > 1)
	s= atoi(argv[1]);  

    std::vector<int> v(s);
    for (auto& x : v)
	x= pick(1, s);

    std::vector<int> w(v), x(v);

    sort_as(seq, v);
    sort_as(par, w);
    sort_as(par_unseq, x);

#else
    std::cerr << "Parallel STL not supported yet by this compiler.\n";
#endif
    
   return 0 ;
}

 
#if 0
Sorting 10 million entries

On an AMD A8 - 7410 APU with AMD Radeon R5 Graphics 2.20 GHz:

Original output:
Sorting with class std::execution::sequenced_policy took 1.64227s.
Sorting with class std::execution::parallel_policy took 0.570872s.
Sorting with class std::execution::parallel_unsequenced_policy took 0.561317s.

Edited output (for better readability):
Sorting with seq took 1.64227s.
Sorting with par took 0.570872s.
Sorting with par_unseq took 0.561317s.

On an Intel Core i7-8550U 1.8GHz 1.99GHz
Sorting with class std::execution::sequenced_policy took 0.863614s.
Sorting with class std::execution::parallel_policy took 0.220736s.
Sorting with class std::execution::parallel_unsequenced_policy took 0.222648s.



#endif


