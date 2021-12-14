#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::ostream;

template<class T1, class T2>
class A {
  template<class t1, class t2>
    friend ostream& operator<<( ostream& , const A<t1, t2>& );
public:
    explicit A() : a(2.0), b(2.0) {};
    A(T1 aa, T2 bb) : a(aa), b(bb) {};
    A<T1, T2> operator+( const A<T1, T2>& );
    /* Overloading the unary operator ! */
    A<T1, T2> operator!() {
        return A<T1, T2>(-a, -b);
    }
    /* Overloading the operator '*' to return a multiplied x10 and b multiplied x20 */
    A<T1, T2> operator*() {
        return A<T1, T2>(a*10, b*20);
    }
private:
    T1 a;
    T2 b;
};

template<class T1, class T2>
A<T1, T2> A<T1, T2>::operator+( const A<T1, T2>& a1)
{
    return A<T1, T2>(this->a+a1.a, this->b+a1.b);
}

template<class T1, class T2>
ostream& operator<<( ostream& out, const A<T1, T2>& a1)
{
    out << "a= " << a1.a << " | b= " << a1.b << endl;
    return out;
}


int main(int argc, char* argv[]) {

    A<int, double> a1, a2(4, 3.0), a3(0,0);

    A<int, double> *ptr;
    a1 = a2;    
    ptr = &a2;

    /* a3 = a1+a2; | Same as below */
    a3 = a1.operator+(a2);
    /* Print a few tests */
    std::cout << "a1: " << a1 << "\na2: " << a2 << "\na3: " << a3;
    std::cout << "!a1: " << !a1;
    std::cout << "*a2: " << *a2;

    return 0;
}