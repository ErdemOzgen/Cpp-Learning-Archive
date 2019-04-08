/*
 * =====================================================================================
 *
 *       Filename:  Triangle.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Triangle
 *
 *        Version:  1.0
 *        Created:  17/08/16 17:54:55
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

#include "Triangle.hpp"

Triangle::Triangle(double b, double h) {
    setBase(b);
    setHeight(h);
}
// set base
void Triangle::setBase(double b) {
    if (b > 0.0f) {
        base = b;
    } else {
        throw std::invalid_argument("Base must be > 0.0f");
    }
}
// get base
double Triangle::getBase() const { return base; }
// set height
void Triangle::setHeight(double h) {
    if (h > 0.0f) {
        height = h;
    } else {
        throw std::invalid_argument("Height must be > 0.0f");
    }
}
// get height
double Triangle::getHeight() const { return height; }
// get area
double Triangle::getArea() const { return (getBase() * getHeight()) / 2.0f; }
// print
void Triangle::print() const {
    std::cout << "Triangle:"
              << "\nbase  : " << getBase() << "\nheight: " << getHeight();
}
