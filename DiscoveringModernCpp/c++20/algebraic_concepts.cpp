#include <list>
#include <vector>
#include <iterator>
#include <ranges>
#include <iostream>
#include <typeinfo>
#include <utility>
#include <type_traits>
#include <concepts>

namespace dmc {
    
// Prototypes of properties used in semantic concepts
// --------------------------------------------------  
    
std::false_type semi_group_map_impl(...);

template <typename Op, typename Value>
constexpr bool semi_group_map= decltype(semi_group_map_impl(std::declval<Op>(), std::declval<Value>()))::value;

std::false_type monoid_map_impl(...);

template <typename Op, typename Value>
constexpr bool monoid_map= decltype(monoid_map_impl(std::declval<Op>(), std::declval<Value>()))::value;


std::false_type commutative_map_impl(...);

template <typename Op, typename Value>
constexpr bool commutative_map= decltype(commutative_map_impl(std::declval<Op>(), std::declval<Value>()))::value;

// Only used for reducing the number of declarations
std::false_type commutative_monoid_map_impl(...);

// most likely not needed
template <typename Op, typename Value>
constexpr bool commutative_monoid_map= decltype(commutative_monoid_map_impl(std::declval<Op>(), std::declval<Value>()))::value;



// Semantic concepts
// ------------------------  
    

template <typename Op, typename Value>
concept Magma =
    requires (Op op, Value x, Value y)
{
    {op(x, y)} -> std::same_as<Value>; // operation must be defined and return same type
    // {op(x, y)} -> std::convertible_to<Value>; // alternatively only convertible
    // same requirements, more clumsily
    // op(x, y);
    // requires std::is_same_v<decltype(op(x, y)), Value>;
    // requires std::is_convertible_v<decltype(op(x, y)), Value>;
};


template <typename Op, typename Value>
concept SemiGroup =
  Magma<Op, Value> && 
  semi_group_map<Op, Value>;



template <typename Op, typename Value>
concept Monoid =
    SemiGroup<Op, Value> &&
    requires (Op op, Value x)
{
    {identity(op, x)} -> std::same_as<Value>;  // request identity operation
    requires monoid_map<Op, Value>;     // semantic declaration that identity behaves correctly
};


template <typename Op, typename Value>
concept Commutative =
    Magma<Op, Value> && 
    commutative_map<Op, Value>;

template <typename Op, typename Value>
concept CommutativeMonoid =
    Monoid<Op, Value> && Commutative<Op, Value>;

  
  
  
  
// Implied declarations of properties
// ----------------------------------  
  
  
// All monoids are semi-groups
template <typename Op, typename Value, typename = std::enable_if_t<monoid_map<Op, Value> > >
std::true_type semi_group_map_impl(Op, Value); 

// The following creates a cyclic dependency and isn't compilable
// template <typename Op, typename Value>
//   requires Monoid<Op, Value>
// std::true_type semi_group_map_impl(Op, Value); 


// All commutative monoids are monoids (obviously)
template <typename Op, typename Value, typename = std::enable_if_t<commutative_monoid_map<Op, Value> > >
std::true_type monoid_map_impl(Op, Value); 

 // All commutative monoids are commutative (obviously)
template <typename Op, typename Value, typename = std::enable_if_t<commutative_monoid_map<Op, Value> > >
std::true_type commutative_map_impl(Op, Value); 
 
  
  
  
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

// Causes ambiguity (bug or feature?)
// template <typename Op, typename Value>
// void dispatch(Op, Value)
//    requires Commutative<Op, Value>
// {
//     std::cout << "Commutative.\n";
// }
// 
template <typename Op, typename Value>
void dispatch(Op, Value)
   requires CommutativeMonoid<Op, Value>
{
    std::cout << "CommutativeMonoid.\n";
}

struct some_op
{
    template <typename T>
    T operator()(T x, T) const noexcept
    {
        return x;
    }    
};

template <typename Value>
Value identity(some_op, Value)
{
    return Value{};
}


struct magma_model {};
struct semi_group_model {};
struct monoid_model {};
struct commutative_model {};
struct commutative_monoid_model {};


std::true_type semi_group_map_impl(some_op, semi_group_model);

std::true_type monoid_map_impl(some_op, monoid_model);

std::true_type commutative_map_impl(some_op, commutative_model);

std::true_type commutative_monoid_map_impl(some_op, commutative_monoid_model);

// std::true_type monoid_map_impl(some_op, commutative_monoid_model);
// std::true_type commutative_map_impl(some_op, commutative_monoid_model);

} // namespace dmc






template <typename Op, typename Value>
void semi_group_only(Op, Value)
  requires dmc::SemiGroup<Op, Value>
{
    std::cout << "(" << typeid(Op).name() << ", " << typeid(Value).name() << ") model SemiGroup.\n";
}


int main()
{
    using namespace std;
    using namespace dmc;
    
    some_op                  s;
    magma_model              magma;
    semi_group_model         semi_group;
    monoid_model             monoid;
    commutative_model        commutative;
    commutative_monoid_model commutative_monoid;
        
    cout << "semi_group_map<some_op, magma_model> = " << boolalpha << semi_group_map<some_op, magma_model> << endl;
    cout << "semi_group_map<some_op, semi_group> = " << semi_group_map<some_op, semi_group_model> << endl;
    cout << "semi_group_map<some_op, semi_group> = " << SemiGroup<some_op, semi_group_model> << endl;
    
    // semi_group_only(s, magma);
    // semi_group_only(s, semi_group);
    
    dispatch(s, magma);
    dispatch(s, semi_group);
    dispatch(s, monoid);
    dispatch(s, commutative);
    dispatch(s, commutative_monoid);
}
