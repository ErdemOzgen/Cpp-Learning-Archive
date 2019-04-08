/*
 * =====================================================================================
 *
 *       Filename:  Sphere.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  3D Sphere
 *
 *        Version:  1.0
 *        Created:  17/08/16 19:00:08
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "Sphere.hpp"

#include <iostream>
#include <stdexcept>

Sphere::Sphere(double r) { setRadius(r); }
// set radius
void Sphere::setRadius(double r) {
    if (r > 0.0f) {
        radius = r;
    } else {
        throw std::invalid_argument("Radius must be > 0.0f");
    }
}
// get radius
double Sphere::getRadius() const { return radius; }
// get surface area
double Sphere::getArea() const { return 4 * PI * getRadius() * getRadius(); }
// get volume
double Sphere::getVolume() const {
    return (4.0f / 3.0f) * PI * getRadius() * getRadius() * getRadius();
}
// print
void Sphere::print() const {
    std::cout << "Sphere:"
              << "\nRadius: " << getRadius();
}
