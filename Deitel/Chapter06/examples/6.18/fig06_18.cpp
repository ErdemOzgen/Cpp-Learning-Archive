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
#include <iostream>

inline double cube(const double side) { return side * side * side; }

int main(int argc, const char *argv[]) {
    double sideValue;

    std::cout << "Enter the side length of your cube: ";
    std::cin >> sideValue;

    // calculate cube of sideValue and display result
    std::cout << "Volumen of cube with side " << sideValue << " is "
              << cube(sideValue) << std::endl;
    return 0;
}
