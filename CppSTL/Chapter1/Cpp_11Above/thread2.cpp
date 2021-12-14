/*
 * Example II: Creating threads using class overloaded operators/functors
 */
#include <iostream>
#include <thread>
#include <typeinfo>

template<class myType>
class Foo {
    myType num;
public:
    Foo() : num(0.0) {}
    Foo(myType n) : num(n) {}
    Foo(const Foo<myType>& other) : num(other.num) {}
    virtual ~Foo() {}
    /* Foo<myType> operator ()() */ auto operator ()() -> decltype(auto) {
        std::cout << "Threading ... \n" ;
    }
};


int main() 
{
    std::cout << "Starting threading ... \n";
    for(auto i=1; i<6; i++) {
        std::thread myThread( (Foo<int>()) );
        myThread.join();   
    }
    std::cout << "[ DONE ] Starting threading ... \n";

    std::cout << "Main is running now ... \n";

    return 0;
}