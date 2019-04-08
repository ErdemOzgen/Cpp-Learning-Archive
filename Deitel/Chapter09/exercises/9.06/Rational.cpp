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

Rational::Rational(int n, int d) : num(n), den(d) { reduce(); }
Rational::~Rational() {}
// reduce fractions
void Rational::reduce() {
    int GCD = gcd(num, den);

    num /= GCD;
    den /= GCD;
}
int Rational::gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}
// print rational number
std::ostream& Rational::printFloating(std::ostream& out) {
    return out << num << "." << den;
}
void Rational::print() { std::cout << num << "/" << den; }
