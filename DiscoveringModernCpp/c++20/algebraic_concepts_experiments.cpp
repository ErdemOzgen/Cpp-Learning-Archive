#include <list>
#include <vector>
#include <iterator>
#include <ranges>
#include <iostream>
#include <typeinfo>
#include <utility>
#include <type_traits>

namespace dmc {
    
template <typename Op, typename Value>
concept Magma =
  requires (Op op, Value x, Value y)
{
    op(x, y);
    // std::is_same_v<decltype(op(x, y)), Value>;
    std::is_convertible_v<decltype(op(x, y)), Value>;
    //op(x, y) -> Value;
};


std::false_type semi_group_map_impl(...);

template <typename Op, typename Value>
constexpr bool semi_group_map= decltype(semi_group_map_impl(std::declval<Op>(), std::declval<Value>()))::value;

template <typename Op, typename Value>
concept SemiGroup =
  Magma<Op, Value> && 
  requires (Op op, Value x)
{
    semi_group_map<Op, Value>; // semantic declaration stating associativity
};



std::false_type monoid_map_impl(...);

template <typename Op, typename Value>
constexpr bool monoid_map= decltype(monoid_map_impl(std::declval<Op>(), std::declval<Value>()))::value;

template <typename Op, typename Value>
concept Monoid =
  SemiGroup<Op, Value> &&
  requires (Op op, Value x)
{
    identity(op, x);  // request identity operation
    // identity(op, x) -> Value;  // request identity operation
    monoid_map<Op, Value>;     // semantic declaration that identity behaves correctly
};



std::false_type commutative_map_impl(...);

template <typename Op, typename Value>
constexpr bool commutative_map= decltype(commutative_map_impl(std::declval<Op>(), std::declval<Value>()))::value;

template <typename Op, typename Value>
concept Commutative =
  Magma<Op, Value> && 
  requires (Op op, Value x)
{
    commutative_map<Op, Value>; // semantic declaration stating associativity
};



template <typename Op, typename Value>
concept CommutativeMonoid =
  Monoid<Op, Value> && Commutative<Op, Value>;

  
  
  
  
  
struct add
{
    template <typename T>
    T operator()(T x, T y) const noexcept
    {
        return x + y;
    }    
};

template <typename Value>
Value identity(add, Value)
{
    return Value{0};
}

template <typename Value>
std::true_type semi_group_map_impl(add, Value);

template <typename Value>
std::true_type monoid_map_impl(add, Value);

template <typename Value>
std::true_type commutative_map_impl(add, Value);





template <typename T>
concept range = requires(T& t) {
  begin(t); 
  end  (t);
};

template <typename T>
concept random_access_range =
    range<T> && std::random_access_iterator<std::ranges::iterator_t<T>>;		


template <std::input_iterator Iter, typename Value, typename Op>
Value accu(Iter first, Iter last, Value init, Op op)
{
    for (; first != last; ++first)
        init= op(init, *first);
    return init;
}

template <range R, typename Value, typename Op>
Value accu(const R& r, Value init, Op op)
{
    std::cout << "Ordinary range with " << typeid(r).name() << '\n';
    auto first= begin(r), last= end(r);
    for (; first != last; ++first)
        init= op(init, *first);
    return init;
}

template <random_access_range R, typename Value, typename Op>
Value accu(const R& r, Value init, Op op)
  requires CommutativeMonoid<Op, Value>
{
    std::cout << "Unrolled implementation with " << typeid(r).name() << '\n';
    auto first= begin(r), last= end(r);
    auto t1= identity(op, *first), t2= t1, t3= t1;
    auto size= last - first;
    auto bsize= size / 4 * 4;
    for (decltype(bsize) i= 0; i < bsize; i+= 4) {
        init= op(init, first[i]);
        t1= op(t1, first[i+1]);
        t2= op(t2, first[i+2]);
        t3= op(t3, first[i+3]);
    }
    return op(op(init, t1), op(t2, t3));
}

template <typename Op, typename Value>
void dispatch(Op, Value)
{
    std::cout << "Unconstrained.\n";
}

template <typename Op, typename Value>
void dispatch(Op, Value)
   requires Magma<Op, Value>
{
    std::cout << "Magma.\n";
}

template <typename Op, typename Value>
void dispatch(Op, Value)
   requires SemiGroup<Op, Value>
{
    std::cout << "SemiGroup.\n";
}

template <typename Op, typename Value>
void dispatch(Op, Value)
   requires Monoid<Op, Value>
{
    std::cout << "Monoid.\n";
}

template <typename Op, typename Value>
void dispatch(Op, Value)
   requires CommutativeMonoid<Op, Value>
{
    std::cout << "CommutativeMonoid.\n";
}

} // namespace dmc


int main()
{
    using namespace std;
    using namespace dmc;
    
    list<int>   li{8, 9, 2, 4, 5};
    vector<int> vi{8, 9, 2, 4, 5};
    
    int sl= accu(begin(li), end(li), 0, add{});
    int sv= accu(begin(vi), end(vi), 0, add{});
    
    int sl2= accu(li, 0, add{});
    int sv2= accu(vi, 0, add{});
    
    dispatch(add{}, 0);
}
