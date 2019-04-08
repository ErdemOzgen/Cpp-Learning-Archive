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
#include "RationalNumber.hpp"

RationalNumber::RationalNumber(int num, int den) {
    if (den < 1) {
        throw new std::invalid_argument(
            "denominator must be greater than zero");
    }
    reduce(num, den);
}
// reduce fractions
void RationalNumber::reduce(int num, int den) {
    int GCD = gcd(num, den);

    numerator = num / GCD;
    denominator = den / GCD;
}
// get GCD
int RationalNumber::gcd(int num, int den) const {
    return den == 0 ? num : gcd(den, num % den);
}
// OVERLOADED OPERATORS
RationalNumber RationalNumber::operator+(const RationalNumber& rn) const {
    return RationalNumber(numerator + rn.numerator,
                          denominator + rn.denominator);
}
RationalNumber RationalNumber::operator-(const RationalNumber& rn) const {
    return RationalNumber(numerator - rn.numerator,
                          denominator - rn.denominator);
}
RationalNumber RationalNumber::operator/(const RationalNumber& rn) const {
    return RationalNumber(numerator * rn.denominator,
                          denominator * rn.numerator);
}
RationalNumber RationalNumber::operator*(const RationalNumber& rn) const {
    return RationalNumber(numerator * rn.numerator,
                          denominator * rn.denominator);
}
bool RationalNumber::operator==(const RationalNumber& rn) const {
    return (numerator == rn.numerator && denominator == rn.denominator);
}
bool RationalNumber::operator!=(const RationalNumber& rn) const {
    return !(*this == rn);
}
// IO OPERATORS
std::ostream& operator<<(std::ostream& out, const RationalNumber& rn) {
    out << '(' << rn.numerator << '/' << rn.denominator << ')';

    return out;
}
std::istream& operator>>(std::istream& in, RationalNumber& rn) {
    in >> rn.numerator >> rn.denominator;

    return in;
}
