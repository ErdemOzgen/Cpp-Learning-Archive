//
// Created by Samuel Martins on 2019-04-22.
//

#ifndef VECTOR_EXAMPLE_VECTOR_CONTAINER_H
#define VECTOR_EXAMPLE_VECTOR_CONTAINER_H

#include "container.h"
#include "vector.h"

#include <iostream>



// The :public can be read as “is derived from” or “is a subtype of.”
class VectorContainer : public Container { // Vector_container implements Container {
private:
    Vector v;
    
public:
    // Objects are constructed “bottom up” (base first) by constructors and destroyed “top down” (derived first)
    // by destructors.
    VectorContainer(long s) : v(s) { } // Vector of s elements
    
    // it overrides the base class
    // Note that the member destructor (~Vector() ) is implicitly invoked by
    // its class’s destructor (~VectorContainer()).
    ~VectorContainer() {
        std::cout << "calling VectorContainer destructor\n";
    }
    
    // The use of override is optional, but being explicit allows the compiler to catch mistake
    double& operator[](int i) override {
        return v[i];
    }
    
    int size() const override {
        return v.size();
    }
    
    // an own implementation of 'xpto' that is only called if the type (not the instanciation) is Vector.
    // if its type is Container, the corresponding function from Container is called because it is not 'virtual'
    // only virtual member functions can be marked 'override'
    void xpto() {
        std::cout << "xpto of VectorContainer class\n";
    }
};


#endif //VECTOR_EXAMPLE_VECTOR_CONTAINER_H
