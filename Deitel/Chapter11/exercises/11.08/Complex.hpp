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

class Complex {
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);

 public:
    explicit Complex(double = 0.0f, double = 0.0f);

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&)const;

    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;

 private:
    double real;
    double imaginary;
};
