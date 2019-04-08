/*
 * =====================================================================================
 *
 *       Filename:  ThreeDimensionalShape.cpp
 *
 *    Description:  Exercie 13.13 - Shape Hierarchy
 *
 *        Version:  1.0
 *        Created:  17/08/16 14:28:27
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <stdexcept>

#include "ThreeDimensionalShape.hpp"

ThreeDimensionalShape::ThreeDimensionalShape(double l, double w, double h)
    : Shape(l, w) {
    setHeight(h);
}
// set length
void ThreeDimensionalShape::setHeight(double h) {
    if (h >= 0.0f) {
        height = h;
    } else {
        throw std::invalid_argument("Length must be >= 0.0f");
    }
}
// get length
double ThreeDimensionalShape::getHeight() const { return height; }
