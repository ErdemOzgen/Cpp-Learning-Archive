/*
 * =====================================================================================
 *
 *       Filename:  Cube.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  3D Cube
 *
 *        Version:  1.0
 *        Created:  17/08/16 18:03:16
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "Cube.hpp"

Cube::Cube(double l, double w, double h) : ThreeDimensionalShape(l, w, h) {
    if (w == 0) { setWidth(l); }
    if (h == 0) { setHeight(l); }
}
// get surface area
double Cube::getArea() const { return 6 * (getLength() * getWidth()); }
// get volume
double Cube::getVolume() const {
    return getLength() * getWidth() * getHeight();
}
// print
void Cube::print() const {
    std::cout << "Cube:"
              << "\nlength: " << getLength() << "\nwidth : " << getWidth()
              << "\nHeight: " << getHeight();
}
