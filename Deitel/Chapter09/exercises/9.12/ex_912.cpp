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
    Coord2D tl(1, 1);
    Coord2D bl(1, 4);
    Coord2D tr(3, 1);
    Coord2D br(3, 4);

    Rectangle r1(tl, bl, tr, br);

    std::cout << "Width: " << r1.getWidth() << "\nLength: " << r1.getLength()
              << "\nArea: " << r1.getArea()
              << "\nPerimeter: " << r1.getPerimeter() << std::endl;
    return 0;
}
