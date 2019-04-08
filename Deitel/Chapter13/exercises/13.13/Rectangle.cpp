/*
 * =====================================================================================
 *
 *       Filename:  Rectangle.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Rectangle
 *
 *        Version:  1.0
 *        Created:  17/08/16 17:35:12
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "Rectangle.hpp"

Rectangle::Rectangle(double l, double w) : TwoDimensionalShape(l, w) {}
// get area
double Rectangle::getArea() const { return getLength() * getWidth(); }
// print
void Rectangle::print() const {
    std::cout << "Rectangle:"
              << "\nLength: " << getLength() << "\nWidth : " << getWidth();
}
