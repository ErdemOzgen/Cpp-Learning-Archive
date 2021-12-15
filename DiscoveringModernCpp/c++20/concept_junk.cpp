
#include <iostream>
#include <type_traits>
#include <concepts>
#include <iterator>
#include <list>
#include <forward_list>
#include <vector>

using namespace std;

template<typename T>
concept Arithmetic 
  = std::is_arithmetic_v<T>;

template<Arithmetic... Args>
bool all(Args... args) { return (... && args); }

template<Arithmetic... Args>
bool any(Args... args) { return (... || args); }

template<Arithmetic... Args>
bool none(Args... args) { return !(... || args); }

template <typename I>
  // requires input_iterator<I>
void adv(I iter, int n) 
  requires input_iterator<I>
{ cout << "InputIterator\n"; }

template <bidirectional_iterator I>
void adv(I iter, int n){ cout << "BiIterator\n"; }

void adv(random_access_iterator auto iter, int n){ cout << "RandomIter\n"; }

template <Arithmetic Value>
class vec {};

template <typename T>
concept Numerical=
  requires(T x, T y)
{
    {x + y} -> same_as<T>;
    {x - y} -> same_as<T>;
    {x * y} -> same_as<T>;
    {x / y} -> same_as<T>;
};

template <typename T>
constexpr bool numerical_v= Numerical<T>;

template <typename T>
struct numerical_trait
{
    static constexpr bool value= Numerical<T>;    
};

template <typename T>
  requires Numerical<T>
//             && numerical_trait<T>::value
//             && numerical_v<T>
void fun(T x) {}

template <typename T>
concept HasOutput= 
  requires(std::ostream& os, const T& x)
{
    {os << x}  -> convertible_to<std::ostream&>;
};
    
struct dummy {};

template <input_iterator I>
void df(I it, int x)
{
    cout << "df: InputIterator\n"; 
}

template <bidirectional_iterator I, typename T>
void df(I it, T x)
{
    cout << "df: BidirectionalIterator\n"; 
}




int main()
{   
    std::cout << std::boolalpha << std::endl;               
    std::cout << "all(5, true, 5.5, false): " << all(5, true, 5.5, false) << std::endl;  
    std::cout << "any(5, true, 5.5, false): " << any(5, true, 5.5, false) << std::endl;               
    std::cout << "none(5, true, 5.5, false): " << none(5, true, 5.5, false) << std::endl;     
    
    vector<int>  v{4, 3, 2};
    list<int>    l{8, 2, 8};
    forward_list f{9, 3, 4};
    
    adv(begin(v), 2);
    adv(begin(l), 2);
    adv(begin(f), 2);
    
    df(begin(l), 2); // both InputIterator
    df(begin(f), 2);
    
    vec<int> vi;
    // vec<string> vi;
    
    fun(3);
    // fun("3");
    
    cout << "int has output: " << boolalpha << HasOutput<int> << endl;
    cout << "dummy has output: " << boolalpha << HasOutput<dummy> << endl;
}

