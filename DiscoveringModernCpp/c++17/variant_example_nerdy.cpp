#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <variant>

using namespace std;

struct record
{
    int ints= 0, doubles= 0,
	strings= 0, symbs= 0;
};

template <typename ...Functors>
struct overloaded : Functors... {
    using Functors::operator()...;
};

template <typename ...Functors>
overloaded(Functors... ) -> overloaded<Functors...>;


int main(int argc, char** argv) 
{
    using my_variant= variant<int, double, string>;
    vector<my_variant> v= {33, 2.3, "Huhu"s, "Dings"s, 11111, 3.809, "Soso"s};

    record r;
    for (const auto& mv : v)
	visit(overloaded{
		[&r](int i){r.ints++;r.symbs+= floor(log10(i)) + 1;},
		[&r](double d){r.doubles++; r.symbs+= 15;},
		[&r](string s){r.strings++; r.symbs+= s.size();}
	      }, mv);

    cout << "We had " << r.ints << " ints, " << r.doubles 
	 << " doubles, and " << r.strings << " strings. " 
	 << "They have " << r.symbs << " symbols in total.\n";
}
