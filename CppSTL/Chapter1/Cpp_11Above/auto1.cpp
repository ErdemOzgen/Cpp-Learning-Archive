#include <iostream>
#include <typeinfo> // decltype
//https://docs.microsoft.com/en-us/cpp/cpp/decltype-cpp?view=msvc-170



using namespace std;

template<class T1, class T2>
class Vector {
public:
    Vector(T1 xx, T2 yy) : x(xx), y(yy) {}
    ~Vector() { x=y=0; }
    Vector(const Vector<T1, T2>& other)
        : x(other.x), y(other.y)
    {}
    virtual auto echo() -> decltype(auto) {
        cout << "Vector v = (" << x << ", " << y << ")\n";
    }//In C++11, you can use the decltype type specifier on a trailing return type, together with the auto keyword, to declare a template function whose return type depends on the types of its template arguments

private:
    Vector() : x(0), y(0) {}
    T1 x;
    T2 y;
};


/*
//C++11
template<typename T, typename U>
auto myFunc(T&& t, U&& u) -> decltype (forward<T>(t) + forward<U>(u))
        { return forward<T>(t) + forward<U>(u); };

//C++14
template<typename T, typename U>
decltype(auto) myFunc(T&& t, U&& u)
        { return forward<T>(t) + forward<U>(u); };
  



*/


template <class T1, class T2>
class Vector2 :public Vector<T1,T2>{
public:
    Vector2(T1 xx, T2 yy) : Vector<T1,T2>(xx,yy){}
    ~Vector2(){}
    Vector2(const Vector2<T1,T2>& other):Vector<T1,T2>(other){}
    auto echo() -> decltype(auto) {
        cout << "Vector2 v = (" << x << ", " << y << ")\n";
        //return different type from parent class...
        return 99;
    }
private:
    Vector2() : x(0), y(0) {}
    T1 x;
    T2 y;
};



int main()
{
    Vector<int,double> v(2.5, 3);
    v.echo();

    Vector<int,double> v2(v);
    v2.echo();
   

    Vector2<int,double> v3(2.5, 3);
    auto returnofV3 =v3.echo();

    cout<< typeid(returnofV3).name() << endl;

    return 0;
}