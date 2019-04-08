/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#include "Rectangle.hpp"

#include <iostream>
#include <stdexcept>

Rectangle::Rectangle(Coord2D topL, Coord2D botL, Coord2D topR, Coord2D botR) {
    setRectangle(topL, botL, topR, botR);
}

// SETTERS
void Rectangle::setRectangle(Coord2D topL, Coord2D botL, Coord2D topR,
                             Coord2D botR) {
    if ((topL.getX() < 20.0f && topL.getY() < 20.0f) &&
        (topR.getX() < 20.0f && topR.getY() < 20.0f) &&
        (botL.getX() < 20.0f && botL.getY() < 20.0f) &&
        (botR.getX() < 20.0f && botR.getY() < 20.0f)) {
        if (topL.getX() != botL.getX() || topR.getX() != botR.getX()) {
            throw std::invalid_argument(
                "Left/Right side X coordinates do not match.");
        } else {
            topLeft = topL;
            bottomLeft = botL;
            topRight = topR;
            bottomRight = botR;

            if (!isRectangle()) {
                throw std::invalid_argument(
                    "Coordinates do not represent a rectangle");
            }
        }
    } else {
        throw std::invalid_argument("Coordinate must be < 20.0");
    }
}
// GETTERS
double Rectangle::getWidth() { return bottomRight.getY() - topRight.getY(); }
double Rectangle::getLength() { return topRight.getX() - topLeft.getX(); }
double Rectangle::getPerimeter() {
    return (2 * getWidth()) + (2 * getLength());
}
double Rectangle::getArea() { return getWidth() * getLength(); }
// check whether current object is rectangle
bool Rectangle::isRectangle() { return getWidth() != getLength(); }
