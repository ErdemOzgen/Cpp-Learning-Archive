/*
 * =====================================================================================
 *
 *       Filename:  Square.hpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Square
 *
 *        Version:  1.0
 *        Created:  17/08/16 15:11:09
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

class Square : public TwoDimensionalShape {
 public:
    explicit Square(int = 0, int = 0, int = 0, int = 0, char = 'x');

    virtual char* draw();
};
