/*
 * =====================================================================================
 *
 *       Filename:  Circle.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Circle
 *
 *        Version:  1.0
 *        Created:  17/08/16 17:45:47
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdexcept>

#include "Circle.hpp"

Circle::Circle(double r) { setRadius(r); }
// set radius
void Circle::setRadius(double r) {
    if (r > 0.0f) {
        radius = r;
    } else {
        throw std::invalid_argument("Radius must be > 0.0f");
    }
}
// get radius
double Circle::getRadius() const { return radius; }
// get area
double Circle::getArea() const { return PI * (getRadius() * getRadius()); }
// print
void Circle::print() const {
    std::cout << "Circle:"
              << "\nradius: " << getRadius();
}
