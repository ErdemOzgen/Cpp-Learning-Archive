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

#include "Rectangle.hpp"

int main(int argc, const char *argv[]) {
    Rectangle r1(19, 19);

    std::cout << "Area: " << r1.getArea()
              << "\nPerimeter: " << r1.getPerimeter() << std::endl;

    return 0;
}
