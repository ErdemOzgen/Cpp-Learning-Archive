/*
 * =====================================================================================
 *
 *       Filename:  Shape.cpp
 *
 *    Description:  Exercie 13.13 - Shape Hierarchy
 *
 *        Version:  1.0
 *        Created:  17/08/16 14:27:24
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <stdexcept>

#include "Shape.hpp"

Shape::Shape(int w, int h, int x, int y) {
    setWidth(w);
    setHeight(h);

    setX(x);
    setY(y);
}
// set width
void Shape::setWidth(int w) {
    if (w >= 0.0f) {
        width = w;
    } else {
        throw std::invalid_argument("Width must be >= 0");
    }
}
// get width
unsigned int Shape::getWidth() const { return width; }
// set height
void Shape::setHeight(int l) {
    if (l >= 0.0f) {
        height = l;
    } else {
        throw std::invalid_argument("Height must be >= 0");
    }
}
// get height
unsigned int Shape::getHeight() const { return height; }
// set x
void Shape::setX(int X) {
    if (X >= 0) {
        x = X;
    } else {
        throw std::invalid_argument("X must be >= 0");
    }
}
// get x
unsigned int Shape::getX() const { return x; }
// set y
void Shape::setY(int Y) {
    if (Y >= 0) {
        y = Y;
    } else {
        throw std::invalid_argument("Y must be >= 0");
    }
}
// get y
unsigned int Shape::getY() const { return y; }
