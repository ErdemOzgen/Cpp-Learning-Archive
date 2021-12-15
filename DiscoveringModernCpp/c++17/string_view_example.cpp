#include <iostream>
#include <typeinfo>
#include <string>
#include <string_view>

#include "../c++11/print_compiler.hpp"

using namespace std;

void print_string_view(string_view sv)
{
    cout << sv << endl;
}



int main (int argc, char* argv[]) 
{
    print_compiler();

    print_string_view("string"s);
    print_string_view("const char*");

    // constexpr string name{"Peter"};
    constexpr string_view name{"Peter"};

    constexpr int size= 100000;
    string      lots_of_as(size, 'a');
    string_view look_at_as(lots_of_as);

    auto half_string=      lots_of_as.substr(0, size/2);
    auto half_string_view= look_at_as.substr(0, size/2);

    cout << "Type of half_string = " << typeid(half_string).name() << endl;
    cout << "Type of half_string_view = " << typeid(half_string_view).name() << endl;
   
    return 0;
}

