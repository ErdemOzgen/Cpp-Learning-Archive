#include <iostream>

#if __has_include(<any>)
#  include <any>
#endif

int main () 
{
#if __has_include(<any>)
    std::cout << "any found, we do something useful.\n";
#else
    std::cerr << "any not found, we have to skip this example.\n";
#endif
    
    return 0 ;
}

