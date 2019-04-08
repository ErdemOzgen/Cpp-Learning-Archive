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

const double PI = 3.14159;//global variable  https://www.geeksforgeeks.org/scope-of-variables-in-c/

int main(int argc, const char *argv[]) {
    int radius;

    std::cout << "Enter an integer value circle radius: ";
    std::cin >> radius;

    std::cout << "Diameter: " << 2 * radius << std::endl;
    std::cout << "Circumference: " << PI * (2 * radius) << std::endl;
    std::cout << "Area: " << PI * (radius * radius) << std::endl;

    return 0;
}
