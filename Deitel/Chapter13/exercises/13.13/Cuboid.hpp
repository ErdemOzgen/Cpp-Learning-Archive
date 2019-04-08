/*
 * =====================================================================================
 *
 *       Filename:  Cuboid.hpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  3D Cuboid
 *
 *        Version:  1.0
 *        Created:  17/08/16 18:47:08
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

class Cuboid : public ThreeDimensionalShape {
 public:
    Cuboid(double, double, double);

    virtual double getArea() const;
    virtual double getVolume() const;
    void print() const;

 private:
};
