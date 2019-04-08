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

class Rational {
 public:
    explicit Rational(int = 1, int = 2);
    ~Rational();

    Rational operator+(const Rational& r) const {
        return Rational(num + r.num, den + r.den);
    }
    Rational operator-(const Rational& r) const {
        return Rational(num - r.num, den - r.den);
    }
    Rational operator*(const Rational& r) const {
        return Rational(num * r.num, den * r.den);
    }
    Rational operator/(const Rational& r) const {
        return Rational(num / r.num, den / r.den);
    }

    friend std::ostream& operator<<(std::ostream& out, Rational& r) {
        return r.printFloating(out);
    }

    void reduce();
    int gcd(int, int);

    void print();

 private:
    int num;
    int den;

    std::ostream& printFloating(std::ostream&);
};
