// Example program for Discovering Modern C++
//
// File: concept_accumulate_semantic.cpp
// Date: 2020-02-20


#include <list>
#include <vector>
#include <iterator>
#include <ranges>
#include <iostream>
#include <typeinfo>
#include <utility>
#include <type_traits>

namespace dmc {
    
template <typename T>
concept Returnable= 
    std::is_move_constructible_v<T> || std::is_copy_constructible_v<T>;
    
template <typename Iter, typename Value, typename Op>    
concept Accumulatable= 
    requires (Iter it, Value init, Op op)
{
    requires std::input_iterator<Iter>;
    requires Returnable<Value>;
    init= op(init, *it);
};    
    
// Explicitly declare properties of CommutativeMonoid:
// Commutativity: op(x, y) == op(y, x)
// Associativity: op(op(x, y), z) == op(x, op(y, z))
// Identity: op(id, x) == op(x, id) == x
std::false_type commutative_monoid_map_impl(...);

template <typename Op, typename Value>
constexpr bool commutative_monoid_map= decltype(commutative_monoid_map_impl(std::declval<Op>(), std::declval<Value>()))::value;

template <typename Op, typename Value>
concept CommutativeMonoid =
  requires (Op op, Value x, Value y)
{
    {op(x, y)} -> std::convertible_to<Value>;
    {identity(op, x)} -> std::convertible_to<Value>;
    requires commutative_monoid_map<Op, Value>;
};


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
std::true_type commutative_monoid_map_impl(add, Value);

template <std::integral Value>
std::true_type commutative_monoid_map_impl(add, Value);


template <typename T>
concept range = requires(T& t) {
  begin(t); 
  end  (t);
};

template <typename Iter, typename Value, typename Op>
Value accumulate(Iter first, Iter last, Value init, Op op)
    requires Accumulatable<Iter, Value, Op>
{
    std::cout << "Ordinary accumulate with " << typeid(first).name() << '\n';
    for (; first != last; ++first)
        init= op(init, *first);
    return init;
}

template <std::random_access_iterator Iter, typename Value, typename Op>
Value accumulate(Iter first, Iter last, Value init, Op op)
  requires Accumulatable<Iter, Value, Op>
           && CommutativeMonoid<Op, Value>
{
    std::cout << "Unrolled implementation with " << typeid(first).name() << '\n';
    auto t1= identity(op, *first), t2= t1, t3= t1;
    auto size= last - first;
    auto bsize= size / 4 * 4;
    for (Iter blast= first + bsize; first != blast; first+= 4) {
        init= op(init, *first);
        t1= op(t1, *(first+1));
        t2= op(t2, *(first+2));
        t3= op(t3, *(first+3));
    }    
    for (; first != last; ++first)
        init= op(init, *first);    
    return op(op(init, t1), op(t2, t3));
}

template <range R, typename Value, typename Op>
Value accumulate(const R& r, Value init, Op op)
{
    return accumulate(begin(r), end(r), init, op);   
}

template <range R, typename Op>
auto accumulate(const R& r, Op op)
    // requires CommutativeMonoid<Op, std::remove_reference_t<decltype(*std::begin(r))>>
    requires CommutativeMonoid<Op, std::ranges::range_value_t<R>>
{
    auto init= identity(op, *begin(r));
    return accumulate(begin(r), end(r), init, op);   
}


}  // namespace dmc


int main()
{
    using namespace std;
    using namespace dmc;
    
    list<int>   li{8, 9, 2, 4, 5};
    vector<int> vi{8, 9, 2, 4, 5};
    
    int sl1= accumulate(begin(li), end(li), 0, add{});
    int sv1= accumulate(begin(vi), end(vi), 0, add{});
    
    int sl2= accumulate(li, 0, add{});
    int sv2= accumulate(vi, 0, add{});
    
    int sl3= accumulate(li, add{});
    int sv3= accumulate(vi, add{});
   
}
