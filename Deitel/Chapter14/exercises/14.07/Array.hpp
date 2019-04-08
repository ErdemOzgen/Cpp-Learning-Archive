#pragma once

#include <iomanip>
#include <iostream>

template <typename T>
class Array {
    template <typename U>
    friend std::istream& operator>>(std::istream&, const Array<U>&);
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Array<U>&);

 public:
    // default constructor
    explicit Array(int arraySize = 10) {
        if (arraySize > 0) {
            size = arraySize;
        } else {
            throw std::invalid_argument("Array size must be greater than 0");
        }

        ptr = new T[size];

        for (int i = 0; i < size; ++i) {
            ptr[i] = 0;
        }
    }
    // copy constructor
    Array(const Array& arrayToCopy) : size(arrayToCopy.size) {
        ptr = new T[size];

        for (int i = 0; i < size; ++i) {
            ptr[i] = arrayToCopy.ptr[i];
        }
    }
    ~Array() { delete[] ptr; }

    Array& operator=(const Array&);
    bool operator==(const Array&) const;
    // inequality operator; returns negative of ==
    bool operator!=(const Array& right) const { return !(*this == right); }

    // subscript operator for non-const objects return modifiable lvalue
    T& operator[](int);
    // subscript operator for const objects returns rvalue
    T& operator[](int) const;

    int getSize() const { return size; }

 private:
    int size;
    T* ptr;  // ptr to first element of pointer based array
};
// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
template <typename T>
Array<T>& Array<T>::operator=(const Array& right) {
    if (&right != this) {  // avoid self assignment
        // for Arrays of different sizes, deallocate original left-side array,
        // then allocate new left-side array
        if (size != right.size) {
            delete[] ptr;
            size = right.size;
            ptr = new T[size];
        }

        for (int i = 0; i < size; ++i) {
            ptr[i] = right.ptr[i];
        }
    }

    return *this;
}
// determine if two Arrays are equal
// true if so false otherwise
template <typename T>
bool Array<T>::operator==(const Array& right) const {
    if (size != right.size) { return false; }

    for (int i = 0; i < size; ++i) {
        if (ptr[i] != right.ptr[i]) { return false; }
    }

    return true;
}
// overloaded subscript operator for non-const Arrays
// reference return creates a modifiable lvalue
template <typename T>
T& Array<T>::operator[](int subscript) {
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size) {
        throw std::out_of_range("Subscript out of range");
    }

    return ptr[subscript];
}
// overloaded subscript operator for const Arrays
// returns rValue
template <typename T>
T& Array<T>::operator[](int subscript) const {
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size) {
        throw std::out_of_range("Subscript out of range");
    }

    return ptr[subscript];
}
// overloaded input operator for class Array
// inputs values for entire Array
template <typename U>
std::istream& operator>>(std::istream& in, const Array<U>& a) {
    for (int i = 0; i < a.size; ++i) {
        in >> a.ptr[i];
    }

    return in;
}
// overloaded output operator for class Array
template <typename U>
std::ostream& operator<<(std::ostream& out, const Array<U>& a) {
    int i = 0;

    // output private ptr-based array
    for (; i < a.size; ++i) {
        out << std::setw(12) << a.ptr[i];

        // 4 numbers per row of output
        if ((i + 1) % 4 == 0) { out << std::endl; }
    }
    // end last line of output
    if (i % 4 != 0) { out << std::endl; }

    return out;
}
