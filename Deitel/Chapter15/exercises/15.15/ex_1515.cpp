/*
 * =====================================================================================
 *
 *       Filename:  ex_1515.cpp
 *
 *    Description:  Exercise 15.15 - Point Class
 *
 *        Version:  1.0
 *        Created:  24/10/16 19:48:34
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "Point.hpp"

int main(int argc, const char *argv[]) {
    Point point;

    std::cout << "Enter space separated x y coordinates: ";
    std::cin >> point;

    std::cout << "You Entered: " << point << std::endl;

    return 0;
}
