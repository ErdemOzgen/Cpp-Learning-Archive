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
#include "Array.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>

// default constructor for class Array (default size 10)
Array::Array(int arraySize) {
    // validate arraySize
    if (arraySize > 0) {
        size = arraySize;
    } else {
        throw std::invalid_argument("Array size must be greater than 0");
    }

    ptr = new int[size];  // create space for pointer-based array

    for (int i = 0; i < size; ++i) {
        ptr[i] = 0;
    }
}
// copy constructor for class Array
// must receive a reference to prevent infinite recursion
Array::Array(const Array& arrayToCopy) : size(arrayToCopy.size) {
    ptr = new int[size];

    for (int i = 0; i < size; ++i) {
        ptr[i] = arrayToCopy.ptr[i];  // copy into object
    }
}
Array::~Array() {
    delete[] ptr;  // release pointer-based array space
}
// return number of elements of Array
int Array::getSize() const { return size; }
// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
const Array& Array::operator=(const Array& right) {
    if (&right != this) {  // avoid self assignment
        // for Arrays of different sizes, deallocate original
        // left-side array, then allocate new left-side array
        if (size != right.size) {
            delete[] ptr;
            size = right.size;
            ptr = new int[size];
        }

        for (int i = 0; i < size; ++i) {
            ptr[i] = right.ptr[i];
        }
    }

    return *this;  // enables x = y = z, for example
}
// determine if two Array are equal and
// return true; false otherwise
bool Array::operator==(const Array& right) const {
    if (size != right.size) {
        return false;  // arrays of different number of elements
    }

    for (int i = 0; i < size; ++i) {
        if (ptr[i] != right.ptr[i]) {
            return false;
        }
    }

    return true;
}
// overloaded subscript operator for non-const Arrays
// reference return creates a modifiable lvalue
int& Array::operator[](int subscript) {
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size) {
        throw std::out_of_range("Subscript out of range");
    }

    return ptr[subscript];
}
// overloaded input operator for class Array
// inputs values for entire Array
std::istream& operator>>(std::istream& input, Array& a) {
    for (int i = 0; i < a.size; ++i) {
        input >> a.ptr[i];
    }

    return input;
}
// overloaded output operator for class Array
std::ostream& operator<<(std::ostream& output, const Array& a) {
    int i = 0;

    // output private ptr-based array
    for (; i < a.size; ++i) {
        output << std::setw(12) << a.ptr[i];

        if ((i + 1) % 4 == 0) {  // 4 numbers per row of output
            output << std::endl;
        }
    }

    if (i % 4 != 0) {  // end last line of output
        output << std::endl;
    }

    return output;
}
