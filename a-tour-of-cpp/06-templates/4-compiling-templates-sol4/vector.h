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
    int size_ = 0;
    T* elem_ = nullptr;

public:
    Vector() {
        std::cout << "default constructor for Vector\n";
    }
    
    // constructor: establish invariant, acquire resources
    explicit Vector(int size);
    
    // destructor: release resources
    ~Vector() {
        delete[] elem_;
    }
    
    
    // ... copy and move operators ...
    
    
    T& operator[](int i) const;
};


// an useless function just to show how to compile template functions in a separate file
template<typename T>
void foo(T& val);

#endif //INC_6_TEMPLATES_VECTOR_H
