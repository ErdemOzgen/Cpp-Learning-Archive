#include <iostream>


int main() {
    int x = 2;
    int y = 3;
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n\n";
    
    int *p = &x; // *p = 2
    int *q = &y; // *q = 3
    std::cout << "*p = " << *p << "\n";
    std::cout << "*q = " << *q << "\n\n";
    
    p = q; // *p == *q = 3
    std::cout << "*p = " << *p << "\n";
    std::cout << "*q = " << *q << "\n\n";
    
    // A reference and a pointer both refer/point to an object and both are represented
    // in memory as machine address.
    // However, the language rules for using them differ.
    // Assignment to a reference does not change what the reference refers to but assigns to
    // the reference object
    
    // r refers to x (it is like a pointer, since it stores the address of x, but it access the value of x directly)
    int &r = x;
    int &r2 = y;
    std::cout << "r = " << r << "\n";
    std::cout << "r2 = " << r2 << "\n\n";
    
    // read through r2, write through r;
    // x becomes 3
    // r continues being a reference to x, then it becomes 3
    r = r2;
    
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
    std::cout << "r = " << r << "\n";
    std::cout << "r2 = " << r2 << "\n\n";
    
    
    return 0;
}
