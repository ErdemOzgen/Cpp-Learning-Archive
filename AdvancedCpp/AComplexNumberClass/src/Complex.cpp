/*
 * Complex.cpp
 *
 *  Created on: 12/11/2021
 *      Author: ERDEMOZGEN
 */

#include "Complex.h"

namespace ComplexNumberNamespace {

ostream &operator<<(ostream &out, const Complex &c) {
	out << "(" << c.getReal() << "," << c.getImaginary() << ")";
	return out;
}

Complex::Complex(): real(0), imaginary(0) {
	// Nothing to do here
}


Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {

}

Complex::Complex(const Complex &other) {
	real = other.real; // you can use this->real = other.real;
	imaginary = other.imaginary; // also this->imaginary = other.imaginary;
}

const Complex &Complex::operator=(const Complex &other) {
	real = other.real;
	imaginary = other.imaginary;

	return *this;
}

}
