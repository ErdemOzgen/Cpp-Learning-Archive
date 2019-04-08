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
#include "Rational.hpp"

int main(int argc, const char *argv[]) {
    Rational r1;
    Rational r2(25, 50);

    std::cout << "r1: " << r1 << "\nr2: " << r2 << std::endl;

    Rational r3 = (r1 + r2);

    return 0;
}
