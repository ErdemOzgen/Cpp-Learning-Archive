//
// Created by Samuel Martins on 2019-04-22.
//

#ifndef VECTOR_EXAMPLE_VECTOR_H
#define VECTOR_EXAMPLE_VECTOR_H

#include <iostream>
#include <initializer_list>



// this user Vector is a container which is an object holding a collection of elements.
class Vector {
private:
    double *elem_;
    long size_;

public:
    // old constructor without error handling
    // constructor: acquire resources
//    Vector(long size) : elem_{new double[size]}, size_{size} {
//        // initialize the elements
//        for (long i = 0; i < size; i++) {
//            elem_[i] = 0;
//        }
//    }

    Vector(long size);
    
    
    // initialize with a list of doubles
    // initializer-list constructor
    // when we use a {} -list, such as {1,2,3,4}, the compiler will create an object of type initializer_list
    // to give to the program.
    Vector(std::initializer_list<double> lst);
    
    
    ~Vector() {
        std::cout << "calling Vector destructor\n";
        delete[] elem_;
    }

    long size() const {
        return size_;
    }
    

    // Returns a reference to the element at position i in the vector
    // it is faster than the method at
    double& operator[](long i) {
        return elem_[i];
    }
    
    
    // Returns a reference to the element at position i in the vector, but it is bound-checked
    // and signals if the requested position is out of range by throwing an out_of_range exception.
    double& at(long i);
    
    
    void print();
};


#endif //VECTOR_EXAMPLE_VECTOR_H
