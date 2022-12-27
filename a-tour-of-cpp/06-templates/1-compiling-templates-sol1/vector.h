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
    explicit Vector(int size) {
        std::cout << "ordinary constructor for Vector\n";
    
        if (size < 0)
            throw std::length_error("Vector constructor: negative size");
    
        size_ = size;
        elem_ = new T[size];
    }
    
    // destructor: release resources
    ~Vector() {
        delete[] elem_;
    }
    
    
    // ... copy and move operators ...
    
    
    // its implementation is in this header files but out of the class declaration
    // it is just another possibility to leave the class declaration cleaner
    T& operator[](int i) const;
};


/*********** IMPLEMENTATIONS **************/
template<typename T>
T& Vector<T>::operator[](int i) const {
    return elem_[i];
}


#endif //INC_6_TEMPLATES_VECTOR_H
