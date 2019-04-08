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
#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, const char *argv[]) {
    double root2 = sqrt(2.0f);  // calculate square root of 2
    int places;                 // precision, vary from 0-9

    std::cout << "Square root of 2 with precisons 0-9." << std::endl
              << "Precision set by ios_base member function "
              << "precision" << std::endl;

    std::cout << std::fixed;  // use fixed-point notation

    // display square root using ios_base function precision.
    for (places = 0; places <= 9; ++places) {
        std::cout.precision(places);
        std::cout << root2 << std::endl;
    }

    std::cout << "\nPrecision set by stream manipulator "
              << " setprecision:" << std::endl;

    // set precision for each digit, then display square root
    for (places = 0; places <= 9; ++places)
        std::cout << std::setprecision(places) << root2 << std::endl;

    return 0;
}
