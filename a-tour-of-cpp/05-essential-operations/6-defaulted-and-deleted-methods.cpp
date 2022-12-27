#include <iostream>

using std::cout;

// Text and codes based on the book: Stephen Prata, "C++ Primer Plus", 6th edition (2012), chapter 18;


// Suppose that you wish to use a defaulted function that, due to circumstances, isn’t created automatically.
// For example, if you provide a "move constructor", then the default constructor, the copy constructor, and
// the copy assignment operator are not provided.
//
// In that case, you can use the keyword `default` to explicitly declare the defaulted versions of these methods:


class Someclass {
public:
    // My own Move Constructor
    Someclass(Someclass &&) { /*...*/ }
    
    // Let's back to use the compiler-generated default constructor, copy constructor and copy assignment
    // The compiler will provide the same constructor that it would have provided automatically
    // had you not provided the move constructor.
    Someclass() = default; // default constructor
    Someclass(const Someclass &) = default; // default copy constructor
    Someclass & operator=(const Someclass &) = default; // default copy assignment
    
    //...
};



int main() {
    
    
    return 0;
}
