#include <iostream>

using std::cout;

// Text and codes based on the book: Stephen Prata, "C++ Primer Plus", 6th edition (2012), chapter 18;


// Now, suppose that we can prevent the compiler from using a particular method.
// To do that, we add the `delete` keyword.


class SomeClass {
public:
    // use compiler-generated default constructor
    SomeClass() = default;
    
    // Disable copy constructor and copy assignment operator:
    SomeClass(const SomeClass &) = delete;
    SomeClass & operator=(const SomeClass &) = delete;
    
    // use compiler-generated move constructor and move assignment operator:
    SomeClass(SomeClass &&) = default;
    SomeClass & operator=(SomeClass &&) = default;
    
    SomeClass operator+(const SomeClass &v) const {
        /* some logic here */
        return SomeClass();
    };
    
    //...
};



int main() {
    // What is the effect of disabling copy methods while enabling move methods?
    // Recall that an rvalue reference, such as used by move operations,
    // binds only to rvalue expressions (temporary objects).
    
    SomeClass one;
    SomeClass two;
    SomeClass three(one); // not allowed, one an lvalue: error: call to deleted constructor of 'SomeClass'
    SomeClass four(one + two); // allowed, expression is an rvalue (the operator+ generates a temporary object)
    
    return 0;
}
