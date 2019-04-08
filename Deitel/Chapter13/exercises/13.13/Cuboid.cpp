/*
 * =====================================================================================
 *
 *       Filename:  Cuboid.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  3D Cuboid
 *
 *        Version:  1.0
 *        Created:  17/08/16 18:48:26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "Cuboid.hpp"

Cuboid::Cuboid(double w, double l, double h) : ThreeDimensionalShape(w, l, h) {}
// get surface area
double Cuboid::getArea() const {
    return (2 * getWidth() * getLength()) + (2 * getLength() * getHeight()) +
           (2 * getHeight() * getWidth());
}
// get volume
double Cuboid::getVolume() const {
    return getLength() * getWidth() * getHeight();
}
// print
void Cuboid::print() const {
    std::cout << "Cuboid: "
              << "\nWidth : " << getWidth() << "\nLength: " << getLength()
              << "\nHeight: " << getHeight();
}
