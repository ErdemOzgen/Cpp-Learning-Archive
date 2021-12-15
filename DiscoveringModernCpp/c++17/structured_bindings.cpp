#include <iostream>
#include <array>
#include <map>
#include <tuple>
#include <utility>
#include <typeinfo>
#include <string>

using namespace std;

namespace dmc {

    template <typename Container>
    auto iterator_pair(Container& container)
    {
	return make_pair(begin(container), end(container));
    }

    auto f() { return tuple<int, double, string>{3, 4.2, "Huhu"s}; }

    // dummies
    class matrix {};
    class vector {}; 

    auto lu(const matrix& A)
    {
	matrix LU(A);
	vector p;

	// ... some computations
	
	// tuple only introduced in chapter four
	// but structured bindings already in chapter three
	return tuple<matrix, vector>(LU, p);
    }
}


int main (int argc, char* argv[]) 
{
    using namespace dmc;

    matrix A;
    auto [LU, p]= lu(A);
    
    auto [a, b, c] = f();
    cout << "a = " << a << ", b = " << b << ", c = " << c << ".\n";

    map<string, int> numbers= {{"Zero", 0}, {"One", 1}, {"Two", 2}};

#if 0
    auto ip= iterator_pair(numbers);
    auto first= ip.first, last= ip.second;
#endif
    
    typename map<string, int>::iterator first2, last2;
    tie(first2, last2)= iterator_pair(numbers);
 
    auto [first3, last3]= iterator_pair(numbers); // C++17 

    for (auto&& p : numbers)
	cout << p.first << "->" << p.second << endl;
 
    for (const auto& [key, value] : numbers) // C++17
	cout << key << "->" << value << endl;

    array<int, 4> ar= {{3, 8, 9, 2}};
    auto [fi, se, th, fo]= ar;

    cout << "ar reverse = {" << fo << ", " << th << ", " << se << ", " << fi << "}\n";

    return 0;
}
 
