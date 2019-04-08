/*
 * =====================================================================================
 *
 *       Filename:  Triangle.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Triangle
 *
 *        Version:  1.0
 *        Created:  17/08/16 17:54:55
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

#include "Triangle.hpp"

Triangle::Triangle(int w, int h, int x, int y, char f)
    : TwoDimensionalShape(w, h, x, y, f) {}
// print
char* Triangle::draw() {
    // create image if none present
    if (img == nullptr) {
        // ensure width is odd number (else triangle won't be centered)
        if (!getWidth() % 2) { setWidth(getWidth() + 1); }

        img = new char[getWidth() * getHeight()];

        unsigned int middle = (getWidth() - 1) / 2;

        for (unsigned int row = 0; row < getHeight(); ++row) {
            for (unsigned int col = 0; col < getWidth(); ++col) {
                if (row == getHeight() - 1 || (row == 0 && col == middle) ||
                    (col == middle - row || col == middle + row)) {
                    img[col + getWidth() * row] = fillchar;
                } else {
                    img[col + getWidth() * row] = ' ';
                }
            }
        }
    }
    return img;
}
