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

class DoubleScriptedArray {
    friend std::ostream& operator<<(std::ostream&, const DoubleScriptedArray&);
    friend std::istream& operator>>(std::istream&, DoubleScriptedArray&);

 public:
    explicit DoubleScriptedArray(int = 10, int = 0);           // default constructor
    DoubleScriptedArray(const DoubleScriptedArray&);  // copy constructor
    ~DoubleScriptedArray();

    int getSize() const;

    DoubleScriptedArray& operator=(const DoubleScriptedArray&);
    bool operator==(const DoubleScriptedArray&) const;

    // inequality operator; returns result of == operator
    bool operator!=(const DoubleScriptedArray& right) const {
        return !(*this == right);  // invokes DoubleScriptedArray::operator==
    }

    // subscript operator for non-const objects return modifiable lvalue
    int& operator()(unsigned int, unsigned int);

    // subscript operator for const objects returns rvalue
    int& operator()(unsigned int, unsigned int) const;

 private:
    size_t COLS;
    size_t ROWS;
    size_t size;

    int* arrPtr;  // pointer to first element of pointer based array
};
