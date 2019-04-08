/*
 * =====================================================================================
 *
 *       Filename:  Point.hpp
 *
 *    Description:  Exercise 15.15 - Point Class
 *
 *        Version:  1.0
 *        Created:  24/10/16 19:47:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include <iostream>

class Point {
 public:
    friend std::ostream& operator<<(std::ostream&, const Point&);
    friend std::istream& operator>>(std::istream&, Point&);

 private:
    int xCoordinate;
    int yCoordinate;
};
