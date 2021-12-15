#include <cassert>
#include <iostream>
#include <chrono>
#include <vector>
#include <typeinfo>
#include <numeric>

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

#ifdef PARSTL
template <typename Policy, typename Value>
void reduce_as(Policy&& p, unsigned rep, std::vector<Value>& v)
{
	auto start = steady_clock::now();
	Value sum{ 0 };
	for (unsigned c = 0; c < rep; ++c)
		sum += reduce(p, begin(v), end(v));
    auto end= steady_clock::now();
    std::cout << "Reducing with " << typeid(p).name() << " took "
	      << duration_ms(start, end) / 1e6 / rep << "s.\n";
	std::cout << "Sum is " << sum << std::endl;
}
#endif


int main(int argc, char** argv)  
{
#ifdef PARSTL
    using namespace std::execution;
    unsigned s= 1000, rep= 10;
    if (argc > 1)
		s= atoi(argv[1]);
	if (argc > 2)
		rep = atoi(argv[2]);

    std::vector<float> v(s);
	iota(begin(v), end(v), 1.0f);

    reduce_as(seq, rep, v);
    reduce_as(par, rep, v);
    reduce_as(par_unseq, rep, v);

#else
    std::cerr << "Parallel STL not supported yet by this compiler.\n";
#endif
    
    return 0 ;
}

 
#if 0
On a AMD A8 - 7410 APU with AMD Radeon R5 Graphics 2.20 GHz:

Original output:
cpp17_parallel_reduce.exe 1'000'000'000
Reducing with class std::execution::sequenced_policy took 1.85599s.
Reducing with class std::execution::parallel_policy took 0.551168s.
Reducing with class std::execution::parallel_unsequenced_policy took 0.509637s.

On a Intel Core i7-8550U 1.8GHz 1.99GHz
Reducing with class std::execution::sequenced_policy took 0.232318s.
Reducing with class std::execution::parallel_policy took 0.167407s.
Reducing with class std::execution::parallel_unsequenced_policy took 0.166975s.

cpp17_parallel_reduce.exe 10000000 100
Reducing with class std::execution::sequenced_policy took 0.00218965s.
Reducing with class std::execution::parallel_policy took 0.00149498s.
Reducing with class std::execution::parallel_unsequenced_policy took 0.00137988s.

#endif


