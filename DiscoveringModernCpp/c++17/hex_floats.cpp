#include <iostream>
#include <typeinfo>

using namespace std;

int main (int argc, char* argv[]) 
{
    std::cout << "0x10.1p0f = " << 0x10.1p0f << '\n';
    std::cout << "type is " << typeid(0x10.1p0f).name() << '\n';
    std::cout << "0x1ffp10 = " << 0x1ffp10    << '\n';
    std::cout << "511*(1<<10) = " << 511*(1<<10)    << '\n';
    
    std::cout << "511.e2 = " << 511.0e2    << '\n';
    std::cout << "0x1.p0 = " << 0xf.p-1    << '\n';
    std::cout << "0x0.123p-1 = " << 0x0.123p-1    << '\n';
    std::cout << "0xa.bp10l = " <<  0xa.bp10l   << '\n';    

    return 0;
}

