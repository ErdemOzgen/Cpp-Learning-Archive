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

class Array {
    friend std::ostream& operator<<(std::ostream&, const Array&);
    friend std::istream& operator>>(std::istream&, Array&);

 public:
    explicit Array(int = 10);      // default constructor
    Array(const Array&);  // copy constructor
    ~Array();

    int getSize() const;

    Array& operator=(const Array&);
    bool operator==(const Array&) const;

    // inequality operator; returns result of == operator
    bool operator!=(const Array& right) const {
        return !(*this == right);  // invokes Array::operator==
    }

    // subscript operator for non-const objects return modifiable lvalue
    int& operator[](int);

    // subscript operator for const objects returns rvalue
    int& operator[](int) const;

 private:
    int size;
    int* ptr;  // pointer to first element of pointer based array
};
