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
    int x() const { return x_; }
    int y() const { return y_; }
    
    void print() {
        cout << "x, y = " << x_ << ", " << y_ << endl;
    }
};


struct RecData {
    Point upper_left;
    Point lower_right;
};


class Rectangle {
private:
    // ugly code. It it just an example to show the problems.
    RecData* data;

public:
    Rectangle(int x0, int y0, int x1, int y1) {
        data = new RecData;
        
        data->upper_left.x(x0);
        data->upper_left.y(y0);
        data->lower_right.x(x1);
        data->lower_right.y(y1);
    }
    
    // We have two solutions for the problem of accessing directly object internals via return handles is:
    // 1. Don't do that: never have a member function return a pointer/reference for data members (object internals).
    // 2. If there is reasons to do that, just simply add `const` to their return types
    // With this altered design, clients can read the Points defining a rectangle, but they can’t write them.
    // This is a deliberate relaxation of encapsulation.
    // More importantly, it’s a limited relaxation: only read access is being granted by these functions.
    // Write access is still prohibited.
    const Point& upperLeft() const { return data->upper_left; }
    const Point& lowerRight() const { return data->lower_right; }
    
    
    // Avoid returning handles (references, pointers, or iterators) to object internals.
    // Not returning handles increases encapsulation, helps const member functions act const, and
    // minimizes the creation of dangling handles.
    
    
    void print() const {
        cout << "Upper Left: (" << data->upper_left.x() << ", " << data->upper_left.y() << ")\n";
        cout << "Lower Right: (" << data->lower_right.x() << ", " << data->lower_right.y() << ")\n";
    }
};


void changeDataMembersInConstObjects(const Rectangle& r) {
    cout << "changeDataMembersInConstObjects\n";
    // compilation errors for these statements
//    r.upperLeft().x(100);
//    r.upperLeft().y(200);
//    r.lowerRight().x(300);
//    r.lowerRight().y(400);
}

int main() {
    Rectangle r{1, 2, 3, 4};
    r.print();
    cout << "\n";
    
    cout << "Changing Data Members directly\n";
    // compilation errors for these statements
//    r.upperLeft().x(-1);
//    r.upperLeft().y(-2);
//    r.lowerRight().x(-3);
//    r.lowerRight().y(-4);
    r.print();
    cout << "\n";
    
    changeDataMembersInConstObjects(r);
    r.print();
    
    return 0;
}

