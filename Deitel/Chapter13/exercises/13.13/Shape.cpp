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

Shape::Shape(double l, double w) {
    setLength(l);
    setWidth(w);
}
// set length
void Shape::setLength(double l) {
    if (l >= 0.0f) {
        length = l;
    } else {
        throw std::invalid_argument("Length must be >= 0.0f");
    }
}
// get length
double Shape::getLength() const { return length; }
// set width
void Shape::setWidth(double w) {
    if (w >= 0.0f) {
        width = w;
    } else {
        throw std::invalid_argument("Width must be >= 0.0f");
    }
}
// get width
double Shape::getWidth() const { return width; }
