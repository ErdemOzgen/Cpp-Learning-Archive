#include <iostream>

using std::cout;

// Text and codes based on the book: Stephen Prata, "C++ Primer Plus", 6th edition (2012), chapter 18;


// Only the six special member functions can be defaulted (= default)
//    SomeClass(parameter(s) of sometype(s)); // "ordinary constructor
//    SomeClass();                            // default constructor
//    SomeClass(const SomeClass&);            // copy constructor
//    SomeClass& operator=(const SomeClass&); // copy assignment: clean up target and copy
//    SomeClass(SomeClass&&);                 // move constructor
//    SomeClass& operator=(SomeClass&&);      // move assignment: clean up target and move
//
//
// However, we can use delete with any member function.

class SomeClass {
public:
    void print(double x) { std::cout << "double x = " << x << "\n"; }
    
    // Disable the implicit conversion from integer to double of the function print()
    // Without this, we could call print(double x) passing an integer.
    void print(int x) = delete;
};



int main() {
    SomeClass c;
    c.print(10.5);
    c.print(10); // compilation error: call to deleted member function 'print'
    
    return 0;
}
