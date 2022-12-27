#include <iostream>
#include <iostream>       // std::cerr
#include <stdexcept>      // std::length_error

#include "vector.h"

int main() {
    Vector v(5);
    
    for (long i = 0; i < v.size(); i++)
        v[i] = i;
    
    
    try {
        for (long i = 0; i < v.size(); i++)
            v.at(i * 10) = i;
    }
    catch (std::out_of_range& err) { // oops: out_of_range error
        std::cout << "Error caught\n";
        std::cerr << err.what() << '\n';
    }
    // we don't need using err
    catch (std::bad_alloc&) { // Ouch! this program is not designed to handle memory exhaustion
        std::terminate(); // terminate the program
    }
    
    return 0;
}