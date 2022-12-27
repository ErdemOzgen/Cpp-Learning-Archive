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


// We include here all definitions/implementations, then it is just a "cleaner" way to have all definitions in the
// header file, as the SOLUTION #1.
// IMPORTANT: The source file CANNOT be listed for compilation in the Makefile/CMake, otherwise we will have
// compilation errors about function redefinitions (see CmakeLists.txt)
#include "vector.cpp"


#endif //INC_6_TEMPLATES_VECTOR_H
