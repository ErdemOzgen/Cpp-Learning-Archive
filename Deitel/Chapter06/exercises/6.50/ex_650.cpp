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
#include <iomanip>
#include <iostream>

const double PI = 3.14159;

// returns the area of a circle from the given radius
inline double circleArea(double r) { return PI * (r * r); }

int main(int argc, const char *argv[]) {
    double radius;

    std::cout << "A program to print the area of a circle from the radius" << std::endl;

    std::cout << "Enter circle radius: ";
    std::cin >> radius;

    std::cout << std::fixed << std::setprecision(2) << "Area: " << circleArea(radius) << std::endl;
    return 0;
}
