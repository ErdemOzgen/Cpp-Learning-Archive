#include <iostream>
#include <cassert>
#include <tuple>
#include <utility>
#include <type_traits>
#include <typeinfo>

#include <initializer_list>
#include <vector>
#include <valarray>
#include <deque>
#include <array>
#include <list>
#include <forward_list>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <memory>

#include <bitset>
#include <functional>
#include <chrono>
#include <complex>

using namespace std;

/// Helper class for foreach_type.
template <typename Types>
struct foreach_type_applicator
{
    static_assert( !std::is_same<Types, Types>::value,    // dummy test to delay error till instantiation
                   "foreach_type_applicator is implemented for std::tuple only.");    
};

template <typename First, typename ...Others>
struct foreach_type_applicator<std::tuple<First, Others...> >
{
    template <typename Functor>
    static inline void apply(Functor f)
    {
        f.template operator()<First>();
        foreach_type_applicator< std::tuple<Others...> >::apply(f);
    }
};

template <>
struct foreach_type_applicator<std::tuple<>>
{
    template <typename Functor, typename ...Args>
    static inline void apply(const Functor&, Args&& ...) {}
};

/// Apply functor \p f with \p args on all \p Types.
template <typename Types, typename Functor>
void foreach_type(Functor f)
{
    foreach_type_applicator<Types>::apply(f);
}

template <typename T>
bool is_equal(const T& x, const T& y)
{
    return x == y;
}

template <typename T>
bool is_equal(const complex<T>& x, const complex<T>& y)
{
    return imag(x) == imag(y) && real(x) == real(y);
}

template <typename T>
bool is_equal(const std::valarray<T>& x, const std::valarray<T>& y)
{
    if (x.size() !=  y.size())
        return false;
    for (auto i1 = begin(x), i2 = begin(y), e = end(x); i1 != e; ++i1, ++i2)
        if (*i1 != *i2)
            return false;
    return true;
}

template <typename T>
bool is_equal(const std::initializer_list<T>& x, const std::initializer_list<T>& y)
{
    if (x.size() !=  y.size())
        return false;
    for (auto i1 = begin(x), i2 = begin(y), e = end(x); i1 != e; ++i1, ++i2)
        if (*i1 != *i2)
            return false;
    return true;
}



template <typename T>
void move_constructor_sanity(T&& x)
{
    if constexpr (is_move_constructible_v<T> || is_copy_constructible_v<T>) {
        if constexpr (is_move_constructible_v<T>) {
            T y{std::move(x)};
            if constexpr(is_default_constructible_v<T>) {
                T z;
                cout << typeid(T).name() << " is move- and default-constructible. Move-from object is "
                     << (is_equal(x, z) ? "equal to" : "different from") << " default-constructed object.\n"; 
                if (!is_equal(x, z) && is_equal(x, y)) 
                    cout << "  Remark: move constructor is actually copy constructor.\n";
                    
            } else {
                cout << typeid(T).name() << " is move- but not default-constructible.\n"; 
                if (is_equal(x, y)) 
                    cout << "  Remark: move constructor is actually copy constructor.\n";
            }
        } else {
            T y{x};
            cout << typeid(T).name() << " is only copy-constructible. Copied-from object is "
                     << (is_equal(x, y) ? "equal to" : "different from") << " target object.\n"; 
        }        
    } else {
        cout << typeid(T).name() << " is neither copy- nor move-constructible.\n";
    }
}


void move_constructor_sanity(function<int(int)>&& x)
{
    using T = function<int(int)>;
    if constexpr (is_move_constructible_v<T> || is_copy_constructible_v<T>) {
        if constexpr (is_move_constructible_v<T>) {
            T y{std::move(x)};
            if constexpr(is_default_constructible_v<T>) {
                T z;
                cout << typeid(T).name() << " is move- and default-constructible. Move-from object is"
                     << (x ? "" : " not") << " callable (like default-constructed).\n"; 
            } else {
                cout << typeid(T).name() << " is move- but not default-constructible.\n"; 
            }
        } else {
            T y{x};
            cout << typeid(T).name() << " is only copy-constructible.\n"; 
        }        
    } else {
        cout << typeid(T).name() << " is neither copy- nor move-constructible.\n";
    }
}

template <typename T>
void move_assignment_sanity(T&& x)
{
    if constexpr (is_move_assignable_v<T> || is_copy_assignable_v<T>) {
        if constexpr (is_move_assignable_v<T>) {
            if constexpr(is_default_constructible_v<T>) {
                T y;
                y = std::move(x);
                T z{};
                cout << typeid(T).name() << " is move-assignable and default-constructible. Move-from object is "
                     << (is_equal(x, z) ? "equal to" : "different from") << " default-constructed object.\n"; 
                if (!is_equal(x, z) && is_equal(x, y)) 
                    cout << "  Remark: move assignment is actually copy assignment.\n";
                    
            } else {
                cout << typeid(T).name() << " is move-assignable but not default-constructible.\n"; 
            }
        } else {
             if constexpr(is_default_constructible_v<T>) {
                T y;
                y = x;
                cout << typeid(T).name() << " is only copy-assignable. Copied-from object is "
                     << (is_equal(x, y) ? "equal to" : "different from") << " target object.\n"; 
             }
        }        
    } else {
        cout << typeid(T).name() << " is neither copy- nor move-assignable.\n";
    }
}


void move_assignment_sanity(function<int(int)>&& x)
{
    using T = function<int(int)>;
    if constexpr (is_move_assignable_v<T> || is_copy_assignable_v<T>) {
        if constexpr (is_move_assignable_v<T>) {
            if constexpr(is_default_constructible_v<T>) {
                T y;
                y = std::move(x);
                T z;
                cout << typeid(T).name() << " is move-assignable and default-constructible. Move-from object is"
                     << (x ? "" : " not") << " callable (like default-constructed).\n"; 
            } else {
                cout << typeid(T).name() << " is move-assignable but not default-constructible.\n"; 
            }
        } else {
            if constexpr(is_default_constructible_v<T>) {
                T y;
                y = x;
                cout << typeid(T).name() << " is only copy-assignable.\n"; 
            }
        }        
    } else {
        cout << typeid(T).name() << " is neither copy- nor move-assignable.\n";
    }
}


struct movable
{
    movable(int i) : i(i) {}
    movable(const movable&) = default;
    movable(movable&& x) { i = x.i; x.i = -999; }
    
    int i;
};



struct no_move
{
    no_move(int i = 0) : m(i) {}
    no_move(const no_move&) = default;
    // no_move(no_move&&) = delete;
    
    ::movable m;
};

int main() 
{
    int a = 10;
    auto r = ref(a);
    cout << "no_move is " << (is_move_constructible_v<no_move>  ? "" : "not ") << "move-constructible.\n";
    cout << typeid(decltype(r)).name() <<  " is " << (is_move_constructible_v<decltype(r)>  ? "" : "not ") << "move-constructible.\n";
    
    ::movable mm(7), mm2(move(mm));                           // moves
    cout <<  "mm.i = " << mm.i << endl;
    
    no_move nm(7), nm2(move(nm));                           // copies
    cout <<  "nm.m.i = " << nm.m.i << endl;
    
#if 0    
    // move_constructor_sanity(initializer_list<int>{1, 2, 3});
    move_constructor_sanity(vector<int>{1, 2, 3});
    move_constructor_sanity(valarray<int>{1, 2, 3});
    move_constructor_sanity(deque<int>{1, 2, 3});
    move_constructor_sanity(array<int, 3>{1, 2, 3});
    move_constructor_sanity(list<int>{1, 2, 3});
    move_constructor_sanity(forward_list<int>{1, 2, 3});
    cout << endl;
    
    move_constructor_sanity(map<int, int>{{1, 2}, {3, 4}});
    move_constructor_sanity(multimap<int, int>{{1, 2}, {3, 4}});
    move_constructor_sanity(set<int>{{1, 2, 3, 4}});
    move_constructor_sanity(multiset<int>{{1, 2, 3, 4}});
    cout << endl;
    
    move_constructor_sanity(unordered_map<int, int>{{1, 2}, {3, 4}});
    move_constructor_sanity(unordered_multimap<int, int>{{1, 2}, {3, 4}});
    move_constructor_sanity(unordered_set<int>{{1, 2, 3, 4}});
    move_constructor_sanity(unordered_multiset<int>{{1, 2, 3, 4}});
    cout << endl;
    
    move_constructor_sanity(unique_ptr<int>(new int(4)));
    move_constructor_sanity(shared_ptr<int>(new int(4)));
    cout << endl;

    move_constructor_sanity(bitset<16>(0b101101));
    move_constructor_sanity(ref(a));
    move_constructor_sanity(function<int(int)>([](int x) {return 3*x;}));
    move_constructor_sanity(chrono::duration<int>(40));
    move_constructor_sanity(chrono::system_clock::now());
    move_constructor_sanity(complex<int>(3, 4));
    move_constructor_sanity(tuple<int, short>(3, 4));
    move_constructor_sanity(string("Hallo Peter"));
# endif

    // move_assignment_sanity(initializer_list<int>{1, 2, 3});
    move_assignment_sanity(vector<int>{1, 2, 3});
    move_assignment_sanity(valarray<int>{1, 2, 3});
    move_assignment_sanity(deque<int>{1, 2, 3});
    move_assignment_sanity(array<int, 3>{1, 2, 3});
    move_assignment_sanity(list<int>{1, 2, 3});
    move_assignment_sanity(forward_list<int>{1, 2, 3});
    cout << endl;
    
    move_assignment_sanity(map<int, int>{{1, 2}, {3, 4}});
    move_assignment_sanity(multimap<int, int>{{1, 2}, {3, 4}});
    move_assignment_sanity(set<int>{{1, 2, 3, 4}});
    move_assignment_sanity(multiset<int>{{1, 2, 3, 4}});
    cout << endl;
    
    move_assignment_sanity(unordered_map<int, int>{{1, 2}, {3, 4}});
    move_assignment_sanity(unordered_multimap<int, int>{{1, 2}, {3, 4}});
    move_assignment_sanity(unordered_set<int>{{1, 2, 3, 4}});
    move_assignment_sanity(unordered_multiset<int>{{1, 2, 3, 4}});
    cout << endl;
    
    move_assignment_sanity(unique_ptr<int>(new int(4)));
    move_assignment_sanity(shared_ptr<int>(new int(4)));
    cout << endl;

    move_assignment_sanity(bitset<16>(0b101101));
    move_assignment_sanity(ref(a));
    move_assignment_sanity(function<int(int)>([](int x) {return 3*x;}));
    move_assignment_sanity(chrono::duration<int>(40));
    move_assignment_sanity(chrono::system_clock::now());
    move_assignment_sanity(complex<int>(3, 4));
    move_assignment_sanity(tuple<int, short>(3, 4));
    move_assignment_sanity(string("Hallo Peter"));
    
    cout << endl;

    return 0;
}
