/*
 * =====================================================================================
 *
 *       Filename:  Square.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Square
 *
 *        Version:  1.0
 *        Created:  17/08/16 15:11:30
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "Square.hpp"

Square::Square(double l, double w) : TwoDimensionalShape(l, w) {
    if (w == 0) { setWidth(l); }
}
// get area
double Square::getArea() const {
    // Square so both width and height are equal
    return getLength() * getWidth();
}
// print
void Square::print() const {
    std::cout << "Square: "
              << "\nLength: " << getLength() << "\nWidth : " << getWidth();
}
