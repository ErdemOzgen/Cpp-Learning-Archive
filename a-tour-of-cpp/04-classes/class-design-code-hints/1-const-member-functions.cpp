#include <iostream>

using std::cout;
using std::endl;


class Point {
private:
    int x_;
    int y_;

public:
    Point() : x_{0}, y_{0} {}
    
    Point(int xin, int yin) : x_{xin}, y_{yin} {}
    
    // 'elegant' setters
    void x(int xin) { x_ = xin; }
    void y(int yin) { y_ = yin; }
    
    // 'elegant' getters
    // ### const Member Functions (text excerpted from: Scott Meyers, "Effective C++ (2005)", Itens 3)
    // The purpose of 'const' on member functions is to identify which member functions may be invoked on `const objects`
    // These functions cannot modify an object (its member data).
    // They are important for two reasons:
    // 1. It is important to know which functions may modify an object and which may not.
    // 2. They make it possible to work with 'const' objects, which is a critical aspect in effective C++ code
    // when passing objects by reference-to-const. This technique is viable only if there are `const member functions`
    // with which to manipulate the resulting const-qualified objects.
    
    // Rule of Thumb: for any member function that does not modify the object, USE const.
    int x() const { return x_; }
    int y() const { return y_; }
    
    void print() const {
        cout << "x, y = " << x_ << ", " << y_ << endl;
    }
};


// Note that `foo()` receives a reference-to-const Pointer as parameter.
// This means that this object is *read-only*; and
// not copy is done (the own object is passed for the function).
// The calls of the functions `x()` and `y()` are only possible because these functions are `const` member functions.
// Otherwise, we would have a compilation error like:
// *error: no matching member function for call to 'x'*
void foo(const Point& p) {
    cout << "foo(const Point& p)\n";
    cout << "x, y = " << p.x() << ", " << p.y() << endl << endl;
}


int main() {
    cout << "P\n";
    Point p = {1, 2};
    p.print();
    cout << "\n";
    foo(p);
    
    return 0;
}