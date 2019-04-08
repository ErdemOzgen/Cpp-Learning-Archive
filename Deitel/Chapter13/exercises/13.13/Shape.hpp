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
    explicit Shape(double = 0.0f, double = 0.0f);

    void setLength(double);
    double getLength() const;

    void setWidth(double);
    double getWidth() const;

    virtual void print() const = 0;

 private:
    double length;
    double width;
};
