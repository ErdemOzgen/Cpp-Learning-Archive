/*
 * =====================================================================================
 *
 *       Filename:  Circle.hpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Circle
 *
 *        Version:  1.0
 *        Created:  17/08/16 17:42:47
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

class Circle : public TwoDimensionalShape {
 public:
    explicit Circle(int = 0, int = 0, int = 0, int = 0, char = 'x');

    virtual char* draw();

 private:
};
