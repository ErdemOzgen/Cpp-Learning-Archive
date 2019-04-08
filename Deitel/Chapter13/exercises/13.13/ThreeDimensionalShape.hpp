/*
 * =====================================================================================
 *
 *       Filename:  ThreeDimensionalShape.hpp
 *
 *    Description:  Exercie 13.13 - Shape Hierarchy
 *
 *        Version:  1.0
 *        Created:  17/08/16 14:28:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "Shape.hpp"

class ThreeDimensionalShape : public Shape {
 public:
    explicit ThreeDimensionalShape(double = 0.0f, double = 0.0f, double = 0.0f);

    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;
    virtual void print() const = 0;

    void setHeight(double);
    double getHeight() const;

 private:
    double height;
};
