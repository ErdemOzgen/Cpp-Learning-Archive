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
#include <iostream>

void printCircle(double);
double getDiameter(double);
double getArea(double);
double getCircumference(double);

const double PI = 3.14159;

int main(int argc, const char *argv[]) {
    double radius;

    std::cout << "Program to print a circle's diameter, circumference and area"
              << std::endl;

    std::cout << "Enter a circles radius: ";
    std::cin >> radius;

    printCircle(radius);

    return 0;
}
void printCircle(double r) {
    std::cout << "Radius: " << r << std::endl;
    std::cout << "Diameter: " << getDiameter(r) << std::endl;
    std::cout << "Area: " << getArea(r) << std::endl;
    std::cout << "Circumference: " << getCircumference(r) << std::endl;
}
double getDiameter(double r) { return r * 2; }
double getArea(double r) { return PI * pow(r, 2); }
double getCircumference(double r) { return 2 * (PI * r); }
