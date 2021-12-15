#include <iostream>
#include <string>
#include <string_view>

using namespace std;

void print_some_string(string_view sv)
{
    cout << sv << '\n';
}

namespace std {
    string operator+(string_view v1, string_view v2)
    {
	return string(v1) + string(v2);
    }    
}

template <typename T>
T twice(T x) // Stale memory in string_view
// auto twice(T x)
{
    return x + x;
}

int main (int argc, char* argv[]) 
{
    print_some_string("const char*");
    print_some_string("string"s);

    unsigned size= 100000;
    string       many_a(size, 'a');
    string_view  many_a_view(many_a);

    string       still_many_a= many_a.substr(0, size/2);
    string_view  still_many_a_view= many_a_view.substr(0, size/2),
	         first_half(&many_a[0], size/2);

    string_view h2= twice("Herbert"sv);
    cout << "h2 is " << h2 << ".\n";
    
    constexpr string_view name= "Herbert";
    
    return 0;
}

