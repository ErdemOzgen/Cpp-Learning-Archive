#include <iostream>
#include <tuple>
#include <string>
#include <typeinfo>
#include <iterator>

using namespace std;

template <typename Number>
struct name_number
{
    // name_number(string name, Number num) : name(name), num(num) {}
    name_number(string name, double num) : name(name), num(num) {}

    string name;
    Number num;
};

name_number(string name, double num) -> name_number<double>;

auto create()
{
    return tuple(3, 3.2f, "text"s);
}

template <typename Value= double>
struct vec
{
    vec(unsigned s) : s(s), d(new Value[s]) {}
    
    vec(std::initializer_list<Value> values)
      : s(values.size()), d(new Value[s]) 
    {
	std::copy(begin(values), end(values), d);
    }

    template <typename Iter>
    vec(Iter beg,  Iter end) 
      : s(distance(beg, end)), d(new Value[s]) 
    {
        copy(beg, end, d);
    }
    
    ~vec() { delete[] d; }
    
    unsigned s;
    Value*   d;
};

template<class Iter>
vec(Iter beg, Iter end) -> vec<typename std::iterator_traits<Iter>::value_type>;

// vec(unsigned s) -> vec<double>;

int main(int argc, char** argv) 
{
    tuple<int, float, string> t1(3, 3.2f, "text"s);

    tuple t2(3, 3.2f, "text"s);
    tuple t3(3, 3.2, string("text"));

    cout << "Stringtyp in t2 ist " << typeid(get<2>(t2)).name() << endl;
    cout << "Stringtyp in t3 ist " << typeid(get<2>(t3)).name() << endl;

    auto [i, f, st]= create();
    cout << "Typ von st ist " << typeid(st).name() << endl;

    name_number horst("Horst", 3.7);
 
    vec v= {2.3, 3.4, 4.5, 5.6};
    cout << "Typ von v ist " << typeid(v).name() << endl;

    int array[] = {3, 4, 5, 6};
    vec w(begin(array), end(array));
    cout << "Typ von w ist " << typeid(w).name() << endl;

    vec x(3); 
    cout << "Typ von x ist " << typeid(x).name() << endl;

    return 0;
}
