#include <iostream>
#include "complex.h"

int main() {
    complex z1; // calls the default constructor (without args)
    std::cout << "## z1" << std::endl;
    z1.print();
    z1.real(2);
    z1.image(3);
    z1.print();
    std::cout << "\n";
    
    std::cout << "## z2" << std::endl;
    complex z2 = {10, 2}; // calls the constructor: complex(double real, double image)
    z2.print();
    std::cout << "\n";

    std::cout << "## z1 += z2" << std::endl;
    z1 += z2;
    z1.print();
    std::cout << "\n";
    
    std::cout << "## z2 += z2" << std::endl;
    z2 += z2;
    z2.print();
    std::cout << "\n";
    
    std::cout << "## z3 = z1 + z2" << std::endl;
    // the function: operator+(complex& a) is called from z1, being z2 passed as argument (reference, actually)
    complex z3 = z1 + z2;
    z3.print();
    std::cout << "\n";
    
    std::cout << "## z1" << std::endl;
    z1.print();
    std::cout << "\n";
    
    std::cout << "## z2" << std::endl;
    z2.print();
    std::cout << "\n";
    
    std::cout << "## z1 == z1: " << (z1 == z1) << std::endl;
    std::cout << "## z1 != z1: " << (z1 != z1) << std::endl;
    std::cout << "## z1 == z2: " << (z1 == z2) << std::endl;
    std::cout << "## z1 != z2: " << (z1 != z2) << std::endl;
    std::cout << "## (z1 + z2) == z3: " << ((z1 + z2) == z3) << std::endl;
    std::cout << "\n";
    
    return 0;
}