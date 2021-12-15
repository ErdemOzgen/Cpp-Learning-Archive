#include <utility>
#include <iostream>
#include <type_traits>
#include <cmath>
#include <typeinfo>

namespace dmc {

#if 0
    template <typename T>
    constexpr std::false_type is_a_matrix(const T&) { return {}; }
#endif
    
    constexpr std::false_type is_a_matrix(...) { return {}; }

    template <typename T>
    using is_matrix= decltype(is_a_matrix(std::declval<T>()));

    template <typename T>
    constexpr bool is_matrix_v= is_matrix<T>::value;
    
    template <typename Value> struct dense_matrix {};
    template <typename Value> struct sparse_matrix {};

    template <typename Value>
    constexpr std::true_type is_a_matrix(const dense_matrix<Value>&)
    { return {}; }

    template <typename Value>
    constexpr std::true_type is_a_matrix(const sparse_matrix<Value>&)
    { return {}; }

    
    struct negate_functor
    {
	template <typename Value>
	Value operator()(const Value& x) const { return -x; }
    };

    struct abs_functor
    {
	template <typename Value>
	Value operator()(const Value& x) const
	{
	    using std::abs;
	    return abs(x);
	}
    };
    

    template <typename Matrix, typename Functor>
    struct map_view
    {
	static_assert(is_matrix_v<Matrix>, "First argument must be a matrix.");
	// ...
    };

    template <typename Matrix, typename Functor>
    constexpr std::true_type is_a_matrix(const map_view<Matrix, Functor>&)
    { return {}; }

    template <typename Matrix>
    struct negate_view
      : map_view<Matrix, negate_functor>
    {};

    template <typename Matrix>
    struct abs_view
      : map_view<Matrix, abs_functor>
    {};

    template <typename T, bool Expected= true>
    void check_matrix()
    {
	std::cout << typeid(T).name() << " is " << (is_matrix_v<T> ? "" : "not ") << "a matrix.\n";
	// static_assert(is_matrix_v<T> == Expected, "Matrix property wrong.");
    }
    
}

int main()
{
    using namespace dmc;
    using namespace std;

    check_matrix<int, false>();
    
    check_matrix<dense_matrix<int>>();
    check_matrix<sparse_matrix<int>>();

    check_matrix<negate_view<dense_matrix<int>>>();
    check_matrix<abs_view<sparse_matrix<int>>>();

}
