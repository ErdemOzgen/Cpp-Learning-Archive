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
#pragma once

#include <iostream>

class RationalNumber {
    friend std::ostream& operator<<(std::ostream&, const RationalNumber&);
    friend std::istream& operator>>(std::istream&, RationalNumber&);

 public:
    explicit RationalNumber(int = 1, int = 1);

    RationalNumber operator+(const RationalNumber&) const;
    RationalNumber operator-(const RationalNumber&) const;
    RationalNumber operator/(const RationalNumber&) const;
    RationalNumber operator*(const RationalNumber&)const;

    bool operator==(const RationalNumber&) const;
    bool operator!=(const RationalNumber&) const;

 private:
    int numerator;
    int denominator;

    void reduce(int, int);
    int gcd(int, int) const;
};
