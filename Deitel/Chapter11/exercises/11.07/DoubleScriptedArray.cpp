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
#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "DoubleScriptedArray.hpp"

// default constructor for class DoubleScriptedArray (default size 10)
DoubleScriptedArray::DoubleScriptedArray(int cols, int rows) {
    // validate arraySize
    if (cols > 0 && rows >= 0) {
        COLS = cols;
        ROWS = rows;

        size = ((ROWS > 0) ? (COLS * ROWS)
                           : COLS);  // avoid multiply by zero error
    } else {
        throw std::invalid_argument("Array size must be greater than 0");
    }

    arrPtr = new int[size];  // create space for pointer-based array

    for (unsigned int i = 0; i < size; ++i) {
        arrPtr[i] = 0;
    }
}
// copy constructor for class DoubleScriptedArray
// must receive a reference to prevent infinite recursion
DoubleScriptedArray::DoubleScriptedArray(const DoubleScriptedArray& arrayToCopy)
    : COLS(arrayToCopy.COLS), ROWS(arrayToCopy.ROWS), size(arrayToCopy.size) {
    arrPtr = new int[size];

    for (unsigned int i = 0; i < size; ++i) {
        arrPtr[i] = arrayToCopy.arrPtr[i];  // copy into object
    }
}
DoubleScriptedArray::~DoubleScriptedArray() {
    delete[] arrPtr;  // release pointer-based array space
}
// return number of elements of DoubleScriptedArray
int DoubleScriptedArray::getSize() const { return size; }
// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
DoubleScriptedArray& DoubleScriptedArray::operator=(
    const DoubleScriptedArray& right) {
    if (&right != this) {  // avoid self assignment
        // for DoubleScriptedArrays of different sizes, deallocate original
        // left-side array, then allocate new left-side array
        if (size != right.size) {
            delete[] arrPtr;
            COLS = right.COLS;
            ROWS = right.ROWS;
            size = right.size;

            arrPtr = new int[size];
        }

        for (unsigned int i = 0; i < size; ++i) {
            arrPtr[i] = right.arrPtr[i];
        }
    }

    return *this;  // enables x = y = z, for example
}
// determine if two DoubleScriptedArray are equal and
// return true; false otherwise
bool DoubleScriptedArray::operator==(const DoubleScriptedArray& right) const {
    if (size != right.size) {
        return false;  // arrays of different number of elements
    }

    for (unsigned int i = 0; i < size; ++i) {
        if (arrPtr[i] != right.arrPtr[i]) {
            return false;
        }
    }

    return true;
}
// overloaded subscript operator for non-const DoubleScriptedArrays;
// reference return creates a modifiable lvalue
int& DoubleScriptedArray::operator()(unsigned int subRow, unsigned int subCol) {
    // check for subscript out-of-range error
    // unsigned so always >= 0
    if (subRow >= ROWS || subCol >= COLS) {
        throw std::out_of_range("Subscript out of range");
    }

    return arrPtr[subCol + COLS * subRow];  // reference return
}
// overloaded subscript operator for const DoubleScriptedArrays;
// const reference return creates an rvalue
int& DoubleScriptedArray::operator()(unsigned int subRow,
                                     unsigned int subCol) const {
    // check for subscript out-of-range error
    // unsigned so always >= 0
    if (subRow >= ROWS ||subCol >= COLS) {
        throw std::out_of_range("Subscript out of range");
    }

    return arrPtr[subCol + COLS * subRow];  // copy return
}

// overloaded input operator for class DoubleScriptedArray
// inputs values for entire DoubleScriptedArray
std::istream& operator>>(std::istream& input, DoubleScriptedArray& a) {
    for (unsigned int i = 0; i < a.size; ++i) {
        input >> a.arrPtr[i];
    }

    return input;
}
// overloaded output operator for class DoubleScriptedArray
std::ostream& operator<<(std::ostream& output, const DoubleScriptedArray& a) {
    for (unsigned int row = 0; row < a.ROWS; ++row) {
        for (unsigned int col = 0; col < a.COLS; ++col) {
            output << a.arrPtr[col + a.COLS * row] << " ";
        }
        output << std::endl;
    }

    return output;
}
