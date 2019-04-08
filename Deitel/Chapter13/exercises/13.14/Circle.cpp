/*
 * =====================================================================================
 *
 *       Filename:  Circle.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Circle
 *
 *                  NOTE: I know this is a poor attempt at a circle and is more
 *                  of a diamond. Best I could manage though.
 *
 *        Version:  1.0
 *        Created:  17/08/16 17:45:47
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdexcept>

#include "Circle.hpp"

Circle::Circle(int w, int h, int x, int y, char f)
    : TwoDimensionalShape(w, h, x, y, f) {}
// print
char* Circle::draw() {
    // create image if none present
    if (img == nullptr) {
        // ensure width and height are equal and even (else circle won't be
        // centered)
        if (getWidth() % 2) { setWidth(getWidth() + 1); }
        if (getWidth() != getHeight()) { setHeight(getWidth()); }

        img = new char[getWidth() * getHeight()];

        unsigned int middle = (getWidth() / 2) - 1;

        for (unsigned int row = 0; row < getHeight(); ++row) {
            for (unsigned int col = 0; col < getWidth(); ++col) {
                if (((row == 0 || row == getHeight() - 1) &&
                     (col == middle || col == middle + 1)) ||
                    ((row == middle || row == middle + 1) &&
                     (col == 0 || col == getWidth() - 1)) ||
                    (row < middle &&
                     (col == middle - row || col == (middle + 1) + row)) ||
                    (row > (middle + 1) &&
                     (col == row - (middle + 1) ||
                      col == (middle + (getWidth() - row))))) {
                    img[col + getWidth() * row] = fillchar;
                } else {
                    img[col + getWidth() * row] = ' ';
                }
            }
        }
    }
    return img;
}
