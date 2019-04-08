/*
 * =====================================================================================
 *
 *       Filename:  Sphere.hpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  3D Sphere
 *
 *        Version:  1.0
 *        Created:  17/08/16 18:58:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "ThreeDimensionalShape.hpp"

class Sphere : public ThreeDimensionalShape {
 public:
    explicit Sphere(double);

    virtual double getArea() const;
    virtual double getVolume() const;
    virtual void print() const;

    void setRadius(double);
    double getRadius() const;

 private:
    const double PI = 3.14159;
    double radius;
};
