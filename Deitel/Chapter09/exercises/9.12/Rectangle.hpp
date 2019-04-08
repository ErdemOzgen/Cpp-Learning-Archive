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
#pragma once

#include "Coord2D.hpp"

class Rectangle {
 public:
    Rectangle(Coord2D, Coord2D, Coord2D, Coord2D);

    // SETTERS
    void setRectangle(Coord2D, Coord2D, Coord2D, Coord2D);

    // GETTERS
    double getWidth();
    double getLength();
    double getPerimeter();
    double getArea();

    bool isRectangle();

 private:
    Coord2D topLeft;
    Coord2D topRight;
    Coord2D bottomLeft;
    Coord2D bottomRight;
};
