#include <iostream>

using std::cout;


// A template can be defined to accept an "arbitrary number of arguments of arbitrary types".
// Such a template is called a VARIADIC TEMPLATE.
//
// Traditionally, implementing a variadic template has been to separate the "first argument"
// from "the rest" and then "recursively" call the variadic template for the "tail of the arguments".


// Eventually, of course, tail will become empty, so we need the no-argument version of print() to deal with that.
// What we do for no arguments: nothing
void print() {
    cout << "print() - no argmuments\n";
}



// The typename ... indicates that Tail is a sequence of types.
// The Tail... indicates that tail is a sequence of values of the types in Tail.
// A parameter declared with a ... is called a "parameter pack".
// Here, tail is a (function argument) parameter pack where the elements are of the types found in the
// (template argument) parameter pack Tail.
// So, print() can take any number of arguments of any types.
template <typename T, typename ... Tail>
void print(T head, Tail ... tail) {
    cout << "\nvoid print(T head, Tail ... tail)\n";
    
    // A call of print() separates the arguments into a head (the first) and a tail (the rest).
    // The head is printed and then print() is called for the tail.
    cout << head << " ";
    print(tail...);
}



// To avoid coding a print() without arguments, we could check in compilation-time if tail is empty.
// C++17 provides the compilation-if (constexpr specifier declares that it is possible to evaluate the value
// of the function or variable at compile time).
template <typename T, typename ... Tail>
void printCpp17(T head, Tail ... tail) {
    cout << "\nvoid printCpp17(T head, Tail ... tail)\n";
    
    cout << head << " ";
    // If we don’t want to allow the zero-argument case, we can eliminate that print() using a compile-time if
    if constexpr(sizeof...(tail) > 0)
        print(tail...);
}


int main() {
    print("hello", 1, 2.5, 3.0, "oi");
    print();
    
    return 0;
}
