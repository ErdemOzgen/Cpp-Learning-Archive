#include "vector.h"

#include <list>


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

// adding some possible template classes for Vector
template class Vector<int>;
template class Vector<char>;
template class Vector<double>;
template class Vector<std::list<int>>;


template<typename T>
void foo(T& val) {
    std::cout << "val = " << val << "\n";
}

// adding template classes to the template function foo
template void foo<int>(int& val);
