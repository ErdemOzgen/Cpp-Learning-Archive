/*
 * =====================================================================================
 *
 *       Filename:  Shape.hpp
 *
 *    Description:  Exercie 13.13 - Shape Hierarchy
 *
 *        Version:  1.0
 *        Created:  17/08/16 14:26:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

class Shape {
 public:
    explicit Shape(int = 0, int = 0, int = 0, int = 0);
    virtual ~Shape() {}

    void setWidth(int);
    unsigned int getWidth() const;

    void setHeight(int);
    unsigned int getHeight() const;

    void setX(int);
    unsigned int getX() const;

    void setY(int);
    unsigned int getY() const;

    virtual char* draw() = 0;

 private:
    // size of image
    unsigned int width;
    unsigned int height;
    // top left corner coords
    unsigned int x;
    unsigned int y;
};
