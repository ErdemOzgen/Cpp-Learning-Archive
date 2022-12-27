#include <iostream>


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
    // ### const Member Functions (text excerpted from: Scott Meyers, "Effective C++ (2005)", Itens 3, )
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
    
    void print() {
        std::cout << "x, y = " << x_ << ", " << y_ << std::endl;
    }
};


// Note that `foo()` receives a reference-to-const Pointer as parameter.
// This means that this object is *read-only*; and
// not copy is done (the own object is passed for the function).
// The calls of the functions `x()` and `y()` are only possible because these functions are `const` member functions.
// Otherwise, we would have a compilation error like:
// *error: no matching member function for call to 'x'*
void foo(const Point& p) {
    std::cout << "foo(const Point& p)\n";
    std::cout << "x, y = " << p.x() << ", " << p.y() << std::endl << std::endl;
}


int main() {
    std::cout << "P1\n";
    Point p1;
    p1.print();
    std::cout << "\n";
    foo(p1);
    
    std::cout << "P2\n";
    Point p2{10, 20};
    p2.print();
    std::cout << "\n";
    
    // this assignment uses an implicity copy operator
    // no constructor is called for p3
    Point p3 = p2;
    p2.x(1);
    p2.y(1);

    std::cout << "P2\n";
    p2.print();
    
    std::cout << "\nP3\n";
    p3.print();
    
    return 0;
}