#include <iostream>

using std::cout;
using std::endl;

// Text based on the book: Stephen Prata, "C++ Primer Plus", 6th edition (2012), chapter 16
//
// A Functor (Function Objects) is any object that can be used with () in the manner of a function.
// This includes normal function names, pointers to functions, and class objects for which the () operator is overloaded
// that is, classes for which the peculiar-looking function operator()() is defined.
//
// Example of a Class to represent a line on a 2D space
class Linear {
private:
    double slope_;
    double y0_;

public:
    Linear(double slope = 1, double y0 = 0) : slope_(slope), y0_(y0) {}
    
    // given a x, returns its corresponding y in the defined line
    double operator()(double x) {
        return y0_ + (slope_ * x);
    }
};




int main() {
    Linear f1; // default: slope=1, y0=0
    Linear f2(2.5, 10.0); // slope=2.5, y0=10
    
    double x1 = 12.5;
    double y1 = f1(x1); // 0 + 1 * 12.5
    cout << "(x1, y1) = (" << x1 << ", " << y1 << ")\n";
    
    double x2 = 0.4;
    double y2 = f2(x2); // 10.0 + 2.5 * 0.4
    cout << "(x2, y2) = (" << x2 << ", " << y2 << ")\n";
    
    return 0;
}

