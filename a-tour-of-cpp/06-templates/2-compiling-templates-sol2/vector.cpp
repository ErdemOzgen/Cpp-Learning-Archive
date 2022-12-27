#include "vector.h"

template <typename T>
Vector<T>::Vector(int size) {
    std::cout << "ordinary constructor for Vector\n";
    
    if (size < 0)
        throw std::length_error("Vector constructor: negative size");
    
    size_ = size;
    elem_ = new T[size];
}


template<typename T>
T& Vector<T>::operator[](int i) const {
    return elem_[i];
}
