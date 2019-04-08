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
#include <iomanip>

inline double min1(double a, double b) { return (a < b ? a : b); }
double minimum(double, double, double);

int main(int argc, const char *argv[]) {
    double d1, d2, d3;

    std::cout << "Program to find the smallest of 3 doubles\n" << std::endl;

    std::cout << "Enter three double values: ";
    std::cin >> d1 >> d2 >> d3;

    std::cout << std::fixed << std::setprecision(1)
              << "Smallest: " << minimum(d1, d2, d3) << std::endl;
    return 0;
}
// finds and returns the smallest of 3 values
double minimum(double d1, double d2, double d3) {
    double min = (d1 < d2 ? d1 : d2);

    return (d3 < min ? d3 : min);
}
