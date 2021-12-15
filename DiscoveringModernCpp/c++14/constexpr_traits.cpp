#include <iostream>
#include <type_traits>
#include <string>
#include <utility>

using namespace std;

namespace le {

    struct base { constexpr void f() const {} string s; };
    struct d1 : base {};
    struct d2 : base {};

    template <typename T>
    struct is_cool_trait
      : false_type {};

    template <>
    struct is_cool_trait<base>
      : true_type {};

    template <typename T>
    constexpr is_cool_trait<T> is_cool_function(const T& t) { return {}; }
    
    // template <typename T>
    // constexpr auto is_cool(const T& t) { return false_type{}; }

    constexpr auto is_cool(...) { return false_type{}; }
    constexpr auto is_cool(const base& b) { return true_type{}; }
    
    // template <typename T>
    // struct is_cool_t
    //   : decltype(is_cool(std::declval<T>()))
    // {};

    template <typename T>
    using is_cool_t= decltype(is_cool(std::declval<T>()));

    template <typename T>
    void is_cool_print(const string& name)
    {
	// cout << name << " is " << (is_cool(T()) ? "" : "not ") << "cool.\n";    
	// cout << name << " is " << (is_cool_function(T()) ? "" : "not ") << "cool.\n";    
	cout << name << " is " << (is_cool_t<T>() ? "" : "not ") << "cool.\n";    
	// is_cool(std::declval<d1>()); triggers static_assert for using declval
    }

}


int main (int argc, char* argv[]) 
{
    using namespace le;

    is_cool_print<int>("int");
    is_cool_print<base>("base");
    is_cool_print<d1>("d1");
    is_cool_print<d2>("d2");
 
    return 0;
}
 
