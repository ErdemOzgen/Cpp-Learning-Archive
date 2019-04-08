/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#include "Rectangle.hpp"

#include <stdexcept>

Rectangle::Rectangle(double l, double w) {
    setLength(l);
    setWidth(w);
}

// SETTERS
void Rectangle::setLength(double l) {
    if (l > 0.0f && l < 20.0f) {
        length = l;
    } else {
        throw std::invalid_argument("Length must be > 0.0 && < 20.0");
    }
}

void Rectangle::setWidth(double w) {
    if (w > 0.0f && w < 20.0f) {
        width = w;
    } else {
        throw std::invalid_argument("Width must be > 0.0 && < 20.0");
    }
}

// GETTERS
double Rectangle::getPerimeter() { return ((2 * length) + (2 * width)); }
double Rectangle::getArea() { return length * width; }
