//
// Created by Samuel Martins on 2019-04-22.
//

#include "vector.h"

#include <iostream>     // std::cerr
#include <stdexcept>    // std::length_error
#include <algorithm>    // std::copy


// the codes that uses this function should use try-catch
Vector::Vector(long size) {
    if (size < 0) {
        throw std::length_error{"Vector constructor: negative size"};
    }
    
    size_ = size;
    elem_ = new double[size];
    for (long i = 0; i < size_; i++)
        elem_[i] = 0;
}


// Unfortunately, the standard-library uses unsigned integers for sizes and subscripts,
// so I need to use the ugly static_cast to explicitly convert the size of the initializer list to an int .
Vector::Vector(std::initializer_list<double> lst)
    : elem_{new double[lst.size()]}, size_{static_cast<int>(lst.size())} {
        std::copy(lst.begin(), lst.end(), elem_); // copy from lst into elem (§12.6)
}


// the codes that uses this function should use try-catch
// In well-designed code try-blocks are rare. Avoid overuse by systematically using the RAII technique
double& Vector::at(long i) {
    if (i < 0 || size() <= i) {
        throw std::out_of_range{"Vector::at"};
    }
    return elem_[i];
}


void Vector::print() {
    std::cout << "size = " << size() << std::endl;
    for (long i = 0; i < size(); i++)
        std::cout << "[" << i << "] = " << elem_[i] << std::endl;
    std::cout << "\n";
}

