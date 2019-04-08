/*
 * =====================================================================================
 *
 *       Filename:  Point.cpp
 *
 *    Description:  Exercise 15.15 - Point Class
 *
 *        Version:  1.0
 *        Created:  24/10/16 19:48:13
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "Point.hpp"

std::ostream& operator<<(std::ostream& out, const Point& point) {
    if (!std::cin.fail()) {
        out << point.xCoordinate << ',' << point.yCoordinate;
    }

    return out;
}

std::istream& operator>>(std::istream& in, Point& point) {
    in >> point.xCoordinate >> point.yCoordinate;

    if ((point.xCoordinate < 0 || point.xCoordinate > 9) ||
        (point.yCoordinate < 0 || point.yCoordinate > 9)) {
        in.setstate(std::ios::failbit);

        point.xCoordinate = 0;
        point.yCoordinate = 0;
    }

    return in;
}
