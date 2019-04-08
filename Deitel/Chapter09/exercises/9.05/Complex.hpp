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
 public:
    explicit Complex(double = 1, double = 1);
    ~Complex();

    // overloaded operators
    Complex operator+(Complex c) const {
        return Complex(real + c.real, imaginary + c.imaginary);
    }
    Complex operator-(Complex c) const {
        return Complex(real - c.real, imaginary - c.imaginary);
    }

    friend std::ostream& operator<<(std::ostream& out, Complex& c) {
        return c.printComplex(out);
    }

 private:
    double real;
    double imaginary;

    std::ostream& printComplex(std::ostream&);
};
