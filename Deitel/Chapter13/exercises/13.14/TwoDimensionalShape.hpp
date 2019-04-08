/*
 * =====================================================================================
 *
 *       Filename:  TwoDimensionalShape.hpp
 *
 *    Description:  Exercie 13.13 - Shape Hierarchy
 *
 *        Version:  1.0
 *        Created:  17/08/16 14:28:03
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

class TwoDimensionalShape : public Shape {
 public:
    explicit TwoDimensionalShape(int = 0, int = 0, int = 0, int = 0, char = 'x');
    ~TwoDimensionalShape();

    virtual char* draw() = 0;

 protected:
    char fillchar;
    char* img = nullptr;
};
