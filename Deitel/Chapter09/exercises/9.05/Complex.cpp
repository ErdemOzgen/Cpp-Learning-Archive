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
#include "Complex.hpp"

Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}
Complex::~Complex() {}
// print complex number
std::ostream& Complex::printComplex(std::ostream& out) {
    out << "(" << real << "," << imaginary << ")";
    return out;
}
