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

class Rectangle {
 public:
    explicit Rectangle(double = 1.0f, double = 1.0f);

    // SETTERS
    void setLength(double);
    void setWidth(double);

    // GETTERS
    double getLength() { return length; }
    double getWidth() { return width; }
    double getPerimeter();
    double getArea();

 private:
    double length;
    double width;
};
