//
// Created by Samuel Martins on 2019-04-25.
//

#ifndef INC_6_TEMPLATES_VECTOR_H
#define INC_6_TEMPLATES_VECTOR_H


#include <iostream>
#include <stdexcept>    // std::length_error
#include <algorithm>    // std::copy


template <typename T>
class Vector {
private:
    int size_;
    T* elem_;

public:
    // constructor: establish invariant, acquire resources
    explicit Vector(int size);
    
    // destructor: release resources
    ~Vector() {
        delete[] elem_;
    }
    
    
    // ... copy and move operators ...
    
    
    T& operator[](int i) const;
};


#endif //INC_6_TEMPLATES_VECTOR_H
