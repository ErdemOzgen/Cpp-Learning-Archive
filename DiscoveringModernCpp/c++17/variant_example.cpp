#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <variant>

// #include <boost/variant.hpp>

using namespace std;

struct record
{
    int counted_ints= 0,
	counted_doubles= 0,
	counted_strings= 0,
	total_symbols= 0;
};

struct symbol_counter
{
    symbol_counter(record& r) : r(r) {}

    void operator()(int i) const
    {
	r.counted_ints++;
	r.total_symbols += static_cast<int>(floor(log10(i))) + 1;
    }

    void operator()(double d) const
    {
	r.counted_doubles++;
	r.total_symbols+= 15;
    }
    
    void operator()(string s) const
    {
    	r.counted_strings++;
    	r.total_symbols+= static_cast<int>(s.size());
    } 
  private:   
    record& r;
};


int main(int argc, char** argv) 
{
    using my_variant= variant<int, double, string>;

    my_variant var;
    var= 3;
    var= 4.2;
    var= "Text";

    string s= get<2>(var);
    s= get<string>(var);
    // int i= get<int>(var); // throws std::bad_variant_access

    vector<my_variant> v= {33, 2.3, "Huhu"s, "Dings"s, 11111, 3.809, "Soso"s};

    record r;
    for (const auto& mv : v)
	visit(symbol_counter{r}, mv);

    cout << "We had " << r.counted_ints << " ints, " << r.counted_doubles
	 << " doubles, and " << r.counted_strings << " strings. " 
	 << "They have " << r.total_symbols << " symbols in total.\n";

    return 0;
}
