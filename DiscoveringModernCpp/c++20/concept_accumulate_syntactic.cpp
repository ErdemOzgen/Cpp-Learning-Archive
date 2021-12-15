// Example program for Discovering Modern C++
//
// File: concept_accumulate_syntactic.cpp
// Date: 2020-02-20

#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

namespace dmc
{

#if 0
template <typename Iter, typename Value>    
concept Summable= 
    requires (Iter it, Value init)
{
    requires std::input_iterator<Iter>;
    requires std::is_copy_constructible_v<Value>;
    Value{init};
    init+= *it;
};    
    
template <typename Iter, typename Value>    
concept Summable= 
    requires (Iter it, Value init)
{
    requires std::input_iterator<Iter>;
    requires std::is_move_constructible_v<Value>;
    Value{std::move(init)};
    init+= *it;
};    
#endif    
    
// Concept for types whose values can be returned from a function
// Can also be used for value parameters
template <typename T>
concept Returnable= 
    std::is_move_constructible_v<T> || std::is_copy_constructible_v<T>;
    
// Works the same way (in this context):    
// template <typename T>
// constexpr bool Returnable=
//     std::is_move_constructible_v<T> || std::is_copy_constructible_v<T>;
    
    
template <typename Iter, typename Value>    
concept Summable= 
    requires (Iter it, Value init)
{
    requires std::input_iterator<Iter>;
    requires Returnable<Value>;
    init+= *it;
};  

template <typename Iter, typename Value, typename Op>    
concept Accumulatable= 
    requires (Iter it, Value init, Op op)
{
    requires std::input_iterator<Iter>;
    requires Returnable<Value>;
    init= op(init, *it);
};    
    
    
template <typename Iter, Returnable Value>
Value accumulate(Iter first, Iter last, Value init)
    requires Summable<Iter, Value>
{
    for (; first != last; ++first)
        init+= *first;
    return init;
}

template <typename Iter, typename Value, typename Op>
Value accumulate(Iter first, Iter last, Value init, Op op)
    requires Accumulatable<Iter, Value, Op>
{
    for (; first != last; ++first)
        init= op(init, *first);
    return init;
}

#if 0
template <typename Iter, typename Value, typename Op>
Value accumulate(Iter first, Iter last, Value init, Op op)
    requires requires (Iter it, Value init, Op op)
    {
        requires std::input_iterator<Iter>;
        requires Returnable<Value>;
        init= op(init, *it);
    }
{
    for (; first != last; ++first)
        init= op(init, *first);
    return init;
}
#endif


    
struct add
{
    template <typename T>
    T operator()(T x, T y) const noexcept
    {
        return x + y;
    }    
};

struct dummy {};

struct uncopyable
{
    uncopyable(int v) : v{v} {}
    uncopyable(const uncopyable&) = delete;
    uncopyable(uncopyable&&) = default;
    
    uncopyable& operator+=(const uncopyable& rhs) &
    {
        v+= rhs.v;
        return *this;
    }
    operator int() const { return v; }
    int v;
};
    
struct unmovable
{
    unmovable(int v) : v{v} {}
    unmovable(const unmovable&) = default;
    unmovable(unmovable&&) = delete;
    
    unmovable& operator+=(const unmovable& rhs) &
    {
        v+= rhs.v;
        return *this;
    }
    operator int() const { return v; }
    int v;
};
    
} // namespace dmc

int main()
{
    using namespace dmc;

    list<int>          li{8, 9, 2, 4, 5};
    vector<int>        vi{8, 9, 2, 4, 5};
    vector<dummy>      vd(3);
    uncopyable         au[]= {8, 9, 2, 4, 5};
    unmovable          am[]= {8, 9, 2, 4, 5};
    
    int sl1= accumulate(begin(li), end(li), 0);
    int sv1= accumulate(begin(vi), end(vi), 0);
    // int sd1= accumulate(begin(vd), end(vd), 0);
    uncopyable u1= accumulate(begin(au), end(au), uncopyable{0});
    unmovable  m0{0};
    unmovable  m1= accumulate(begin(am), end(am), m0);

    int sl2= accumulate(begin(li), end(li), 0, add{});
    int sv2= accumulate(begin(vi), end(vi), 0, add{});
    // int sd2= accumulate(begin(vd), end(vd), 0, add{});

    return 0;
}
