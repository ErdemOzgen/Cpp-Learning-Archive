/*
    Polymorphism : Example Une via a Shape that can be a square or a Circle
       Shape --> Interface (Abstract) class
         |
        / \
   square  circle : These two classes implement Shape interface
*/
#include <iostream>
#include <string>

using namespace std;

// improve qoc | a coordinate is an int
typedef int coordinate;

#define PI 3.141593

// Just a class for a Point with left and right coordinates
class Point {
public:
    Point(coordinate x, coordinate y)
        : x(x), y(y) {}
    friend ostream& operator<<(ostream & os, const Point & p) {
        os << " (" << p.x << ", " << p.y << ") ";
        return os;
    }
    coordinate getX() const { return x; }
    coordinate getY() const { return y; }
private:
    coordinate x, y;
};

// The Shape Interface follows : Has a pure virtual function
//
class Shape {
public:
    // Should have a virtual dtor
    virtual ~Shape() = default;
    // this one will be implemented by each class that implements this Shape interface
    // should not de defined in here
    virtual double getSurface() const = 0;
    virtual void describe() const {
        cout << "This is a Shape ...\n";
    }
};

// Square class implements Shape interface
//
class Square : public Shape {
public:
    Square(const Point & begin, double side)
        : start(begin), side_len(side) {}
    // now implement the shape interface (or abstract class | whatever)
    double getSurface() const override {
        return side_len * side_len;
    }
    void describe() const override {
        cout << "This is a Square starting at: ";
        cout << start << " and has a length of: " << side_len << endl;
        cout << "Also the surface is: " << this->getSurface() << endl;
    }
private:
    // A Square starts at (x,y) which are coordinates of Point(x,y) --> start: x, y
    Point start;
    double side_len;
};

// Circle implements Shape interface too
//
class Circle : public Shape {
public:
    Circle(const Point & point, double radius)
        : p(point), radius(radius) {}
    // now implement the shape interface (or abstract class | whatever)
    double getSurface() const override {
        // surface of a circle is : p * r(only in dimension of 'x')
        return PI * p.getX();
    }
    void describe() const override {
        cout << "This is a Circle at: ";
        cout << p << " with a radius of: " << radius << endl;
        cout << "Also the surface is: " << this->getSurface() << endl;
    }
private:
    Point p;
    double radius; 
};

///
/// Lets test all of them now | Polymorphic behavior in action in c++
///
int main() {

    // square indeed
    Square square(Point(2.2, 3.3), 2.5);
    square.describe();

    Circle circle(Point(10, 3), 2);

    // square or maybe circle ??? compiler shall decide regarding this one
    Shape *shape = nullptr;
    shape = &circle;
    shape->describe();

    delete shape;

    return 0;
}