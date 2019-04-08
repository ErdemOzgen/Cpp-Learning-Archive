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

#include "RationalNumber.hpp"

int main(int argc, const char *argv[]) {
    RationalNumber r1(3, 5);
    RationalNumber r2(9, 4);

    std::cout << "r1: " << r1 << "\nr2: " << r2 << std::endl;

    RationalNumber r3 = r1 + r2;

    std::cout << r1 << " + " << r2 << " = " << r3;
    r3 = r1 - r2;
    std::cout << "\n" << r1 << " - " << r2 << " = " << r3;
    r3 = r1 / r2;
    std::cout << "\n" << r1 << " / " << r2 << " = " << r3;
    r3 = r1 * r2;
    std::cout << "\n" << r1 << " * " << r2 << " = " << r3 << std::endl;

    return 0;
}
