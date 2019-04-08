/*
 * =====================================================================================
 *
 *       Filename:  Triangle.hpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Triangle
 *
 *        Version:  1.0
 *        Created:  17/08/16 17:53:50
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

class Triangle : public TwoDimensionalShape {
 public:
    explicit Triangle(int = 0, int = 0, int = 0, int = 0, char = 'x');

    virtual char* draw();
};
