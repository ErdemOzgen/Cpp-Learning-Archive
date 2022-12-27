#ifndef INC_5_A_MORE_ROBUST_VECTOR_VECTOR_H
#define INC_5_A_MORE_ROBUST_VECTOR_VECTOR_H

#include <iostream>
#include <stdexcept>    // std::length_error
#include <algorithm>    // std::copy


using std::cout;
using std::endl;


// Since our own Vector container must store generic elements, we need to use a Template for it.
// Since its generic elements can have any datatype (classes or built-in), we put all of its code only in the header,
// due to the problems to compile Template codes in separated files (.h and .cpp).
//
// If our Vector was designed to deal with just a few dataypes, we could separated the declarations and definitions
// in a header and source file, respectively, and then indicate these dataypes in the source file:
// e.g:
// template class Vector<int>;
// template class Vector<double>;
// template class Vector<string>;
//
// See a complete explanation in the examples: ../*compiling-templates-sol*


template <typename T>
class Vector {
private:
    int size_ = 0;
    T *elem_ = nullptr;

public:
    Vector() { }
    
    // constructor: establish invariant, acquire resources
    explicit Vector(int size) {
        cout << "ordinary constructor for Vector\n";
    
        if (size < 0)
            throw std::length_error("Vector constructor: negative size");
    
        size_ = size;
        elem_ = new T[size];
    }
    
    
    Vector(std::initializer_list<T> lst)
            : elem_{new T[lst.size()]}, size_{static_cast<int>(lst.size())} {
        cout << "initializer-list constructor for Vector\n";
        
        std::copy(lst.begin(), lst.end(), elem_);
    }
    
    
    ~Vector() {
        delete[] elem_;
    }
    
    
    // copy constructor
    Vector(const Vector& v) : elem_{new T[v.size_]}, size_{v.size_} {
        cout << "Copy Constructor for Vector\n";
        
        for (int i = 0; i != v.size_; i++) // copy elements
            elem_[i] = v.elem_[i];
    }
    
    
    // copy assignment
    Vector& operator=(const Vector& v) {
        cout << "Copy Assignment for Vector\n";
        
        T* elem = new T[v.size_];
        
        for (int i = 0; i != v.size_; i++) // copy elements
            elem[i] = v.elem_[i];
        
        delete[] elem_; // delete old elements from the this/current object
        
        elem_ = elem;
        size_ = v.size_;
        
        return *this;
    }
    
    
    // move constructor
    Vector(Vector&& v) :
            elem_{v.elem_},
            size_{v.size_}
    {
        cout << "Move Constructor for Vector\n";
        
        v.elem_ = nullptr; // now v has no elements
        v.size_ = 0;
    }
    
    
    // move assignment
    Vector& operator=(Vector&& v) {
        cout << "Move Assignment for Vector\n";
        
        // if the object isn't being called on itself
        if (this != &v) {
            delete[] elem_; // delete the object data
            
            // "Move" v's data into the current object
            elem_ = v.elem_;
            size_ = v.size_;
            
            // Mark the v object as "empty"
            v.elem_ = nullptr; // now v has no elements
            v.size_ = 0;
            
            return *this;
        }
    }
    
    
    const T& operator[](int i) const {
        cout << "const T& operator[](int i) const" << endl;
    
        return elem_[i];
    }
    
    
    T& operator[](int i) {
        cout << "T& operator[](int i)" << endl;
        
        return const_cast<T&>(static_cast<const Vector&>(*this)[i]);
    }
    
    
    const T& at(int i) const {
        cout << "const T& at(int i) const" << endl;
    
        if (i < 0 || size() <= i)
            throw std::out_of_range{"Vector::at"};
        
        return elem_[i];
    }
    
    T& at(int i) {
        cout << "T& at(int i)" << endl;
        
        return const_cast<T&>(static_cast<const Vector&>(*this).at(i));
    }
    
    
    // With the begin() and end() functions below, we can now iterate over our container with range-for (see test2.cpp)
    // Since these functions returns the address for an internal data (resource handle), we need to have their versions
    // for const and non-const objects
    
    // without this version, const objects could modify the internal data.
    const T* begin() const {
        cout << "const T* begin() const\n";
        return size_ ? &elem_[0] : nullptr; // pointer to first element or nullptr
    }
    
    
    T* begin() {
        cout << "T* begin()\n";
        return const_cast<T*>(static_cast<const Vector&>(*this).begin());
    }
    
    
    // iterators
    const T* end() const {
        cout << "const T* end() const\n";
        return size_ ? &elem_[size_] : nullptr; // pointer to one-past-last element (next address after the last element)
    }
    
    
    T* end() {
        cout << "T* end()\n";
        return const_cast<T*>(static_cast<const Vector&>(*this).end());
    }
    
    
    // We do not have a setters for size, because this is non-sense and dangerous.
    // The user could change the size of the Vector (i.e., its private data member size), but its array has
    // a different number of elements allocated.
    int size() const {
        return size_;
    }
    
    void print() const {
        cout << "size = " << size_ << endl;
        
        for (int i = 0; i < size_; i++)
            cout << "[" << i << "] = " << elem_[i] << "\n";
    }
};


// Defining our own Output <ostream>
// This function is called when: cout << v;
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T> v) {
    os << "size = " << v.size() << endl;
    
    for (int i = 0; i < v.size(); i++)
        os << "[" << i << "] = " << v[i] << "\n";
    
    return os;
}


#endif //INC_5_A_MORE_ROBUST_VECTOR_VECTOR_H
