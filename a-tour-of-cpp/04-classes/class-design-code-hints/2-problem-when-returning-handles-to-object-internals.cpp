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
    
    // The text below is based on the book: *Scott Meyers, "Effective C++ (2005)", Item 28*
    // These const member functions will compile, but they're wrong and self-contradictory.
    // They are const member functions for two reasons:
    // 1. they are designed to only to offer clients a way to learn what the Rectangle’s points are,
    // not to let clients modify the Rectangle
    // 2. We can now use theses functions for `const` objects.
    
    // On the other hand, both functions return references to private internal data,
    // references that callers can use to modify that internal data (even for const object),
    // breaking the data encapsulation (see main and function changeDataMembersInConstObjects())
    // See the solution in file:
    Point& upperLeft() const { return data->upper_left; }
    Point& lowerRight() const { return data->lower_right; }
    
    
    void print() const {
        cout << "Upper Left: (" << data->upper_left.x() << ", " << data->upper_left.y() << ")\n";
        cout << "Lower Right: (" << data->lower_right.x() << ", " << data->lower_right.y() << ")\n";
    }
};


void changeDataMembersInConstObjects(const Rectangle& r) {
    cout << "changeDataMembersInConstObjects\n";
    r.upperLeft().x(100);
    r.upperLeft().y(200);
    r.lowerRight().x(300);
    r.lowerRight().y(400);
}

int main() {
    Rectangle r{1, 2, 3, 4};
    r.print();
    cout << "\n";
    
    cout << "Changing Data Members directly\n";
    r.upperLeft().x(-1);
    r.upperLeft().y(-2);
    r.lowerRight().x(-3);
    r.lowerRight().y(-4);
    r.print();
    cout << "\n";
    
    changeDataMembersInConstObjects(r);
    r.print();
    
    return 0;
}

