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
#include <math.h>
#include <iomanip>
#include <iostream>

double hypotenuse(double, double);

int main(int argc, const char *argv[]) {
    std::cout << "Triangle" << std::setw(10) << "Side1" << std::setw(10)
              << "Side2" << std::setw(15) << "Hypotenuse" << std::endl;

    std::cout << "1" << std::setw(15) << "3.0" << std::setw(10) << "4.0"
              << std::setw(8) << hypotenuse(3.0, 4.0) << std::endl;

    std::cout << "2" << std::setw(15) << "5.0" << std::setw(11) << "12.0"
              << std::setw(8) << hypotenuse(5.0, 12.0) << std::endl;

    std::cout << "3" << std::setw(15) << "8.0" << std::setw(11) << "15.0"
              << std::setw(8) << hypotenuse(8.0, 15.0) << std::endl;
    return 0;
}
// calculate the hypotenuse of a right triangle with two given sides
double hypotenuse(double sideA, double sideB) {
    return sqrt(pow(sideA, 2) + pow(sideB, 2));
}
