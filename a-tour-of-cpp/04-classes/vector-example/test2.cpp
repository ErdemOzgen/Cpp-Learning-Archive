#include <iostream>
#include <iostream>       // std::cerr
#include <stdexcept>      // std::length_error

#include "vector.h"


// non-sense code just to check the 'automatic' destroyers
void function(long n) {
    Vector v(n);
    
    // use v
    for (long i = 0; i < v.size(); i++) {
        v[i] = i;
    }
    std::cout << "v" << std::endl;
    v.print();
    
    
    if (n > 0) {
        Vector v2(n);
        // use v and v2
        for (long i = 0; i < v2.size(); i++) {
            v2[i] = i;
        }
        
        std::cout << "v" << std::endl;
        v.print();
        std::cout << "v2" << std::endl;
        v2.print();
    } // v2 is destroyed here
    

    std::cout << "v" << std::endl;
    v.print();
} // v is destroyed here


int main() {
    function(5);
    
    return 0;
}
