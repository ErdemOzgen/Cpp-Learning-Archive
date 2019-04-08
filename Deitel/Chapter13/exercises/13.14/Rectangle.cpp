/*
 * =====================================================================================
 *
 *       Filename:  Rectangle.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *                  2D Rectangle
 *
 *        Version:  1.0
 *        Created:  17/08/16 17:35:12
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "Rectangle.hpp"

Rectangle::Rectangle(int h, int w, int x, int y, char f)
    : TwoDimensionalShape(h, w, x, y, f) {}
// print
char* Rectangle::draw() {
    // create image if none present
    if (img == nullptr) {
        img = new char[getWidth() * getHeight()];

        for (unsigned int row = 0; row < getHeight(); ++row) {
            for (unsigned int col = 0; col < getWidth(); ++col) {
                if (col == 0 || col == getWidth() - 1 || row == 0 ||
                    row == getHeight() - 1) {
                    img[col + getWidth() * row] = fillchar;
                } else {
                    img[col + getWidth() * row] = ' ';
                }
            }
        }
    }
    return img;
}
