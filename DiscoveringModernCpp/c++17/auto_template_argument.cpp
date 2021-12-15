#include <iostream>
#include <type_traits>
#include <typeinfo>

#include "../c++11/print_compiler.hpp"

using namespace std;

#if 0 
template<typename T, T Value>
struct integral_constant
{
    using value_type= T;
    using type= integral_constant<T, Value>;
    
    static constexpr T value = Value;
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; } //since C++14
};
#endif

namespace dmc {

    template <auto Value>
    struct integral_constant_c
      : std::integral_constant<decltype(Value), Value>
    {};

    template <auto Value>
    using integral_constant_t= std::integral_constant<decltype(Value), Value>;
}



int main (int argc, char* argv[]) 
{
    print_compiler();
    using namespace dmc;

    using f_type= integral_constant_c<false>;
    cout << "f_type is " << typeid(f_type).name() << ".\n";
    cout << "value_type of f_type is " << typeid(typename f_type::value_type).name() << ".\n";
    cout << "Its value is " << boolalpha << f_type::value << ".\n\n";
    
    using t_type= integral_constant_t<true>;
    cout << "t_type is " << typeid(t_type).name() << ".\n";
    cout << "value_type of t_type is " << typeid(typename t_type::value_type).name() << ".\n";
    cout << "Its value is " << boolalpha << t_type::value << ".\n\n";

    return 0;
}

