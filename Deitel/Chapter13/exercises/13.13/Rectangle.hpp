/*
 * =====================================================================================
 *
 *       Filename:  Rectangle.hpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Rectangle
 *
 *        Version:  1.0
 *        Created:  17/08/16 17:33:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "TwoDimensionalShape.hpp"

class Rectangle : public TwoDimensionalShape {
 public:
    explicit Rectangle(double = 0.0f, double = 0.0f);

    virtual double getArea() const;
    virtual void print() const;

 private:
};
