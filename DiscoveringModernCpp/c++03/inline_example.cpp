#include <iostream>
#include <typeinfo>

inline int f(int i) { return i + 3; }

template <typename F>
int g(F f, int i)
{
    // std::cout << "&f = " << std::hex << &f << '\n';    
    return f(i);
}

int main (int argc, char* argv[]) 
{
    std::cout << "f(4) = " << f(4) << '\n';
    std::cout << "&f = " << std::hex << &f << '\n';
    std::cout << "type of &f = " << typeid(&f).name() << '\n';
    g(f, 5);

    // long af= (long)(&f);
    // std::cout << "&f = " << std::hex << af << '\n';
    // std::cout << "&af = " << std::hex << &af << '\n';
    
    
    
    return 0;
}
 
