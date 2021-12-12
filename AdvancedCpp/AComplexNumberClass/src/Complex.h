/*
 * Complex.h
 *
 *  Created on: 12/11/2021
 *      Author: ERDEM OZGEN
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace ComplexNumberNamespace {

class Complex {
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);
	const Complex &operator=(const Complex &other);

	double getReal() const {
		return real;
	}
	double getImaginary() const {
		return imaginary;
	}
};

ostream &operator<<(ostream &out, const Complex &c);

}

#endif /* COMPLEX_H_ */
