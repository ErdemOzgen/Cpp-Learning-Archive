//
// Created by Samuel Martins on 2019-04-02.
//

#ifndef TOUR_CPP_COMPLEX_COMPLEX_H
#define TOUR_CPP_COMPLEX_COMPLEX_H

#include <iostream>


class complex {
private:
    // members without visibility modifiers are private by default
    // as a coding convention, let's put _ at the end of class member names
    // this style is mentioned at book: C++ Primer 6th, Chapter 10 Objects and Classes, page 526
    double real_, image_;

public:
    complex() : real_{0}, image_{0} {std::cout << "Default Constructor: complex()" << std::endl;}
    complex(double real) : real_{real}, image_{0} {}
    complex(double real, double image) : real_{real}, image_{image} {std::cout << "Constructor: complex(double real, double image)" << std::endl;}

    // short functions (up to 5 rows) are supposed to be in the header file
    
    // setter
    void real(double in_real) {
        real_ = in_real;
        // this->real_ = in_real; // let's avoid using 'this' to have a less verbose code
    }
    
    // getter: const does not allow to change members from the class
    double real() const {
        return real_;
    }
    
    // we could use the prefix m_ for the method parameters to better identify it as a parameter
    void image(double in_image) {
        image_ = in_image;
    }
    
    double image() const {
        return image_;
    }
    
    
    // operator overloading
    // it receives a copy (z) of a different complex object, changes the content of the current object,
    // and returns the reference of the current object
    // this avoids to copy the current (changed) object to itself when doing: z1 += z2;
    complex& operator+=(const complex& z) {
        // a private member from an object passed as an argument can be accessed directly inside the function
        // if the object is of the current class
        real_ += z.real_;
        
        // to strictly respect OO, let us use getters instead
        image_ += z.image();
       
        // 'this' is a pointer to the class/current object
        // so, *this corresponds to the own object
        // as the function returns a reference, a copy of the current object is not returned
        return *this;
    }
    
    
    complex& operator-=(const complex& z) {
        real_ -= z.real();
        image_ -= z.image();
        
        return *this;
    }
    
    
    // current_object + another_object
    // this function is called by the current_object
    // 'const' guarantees that the (this) members are not changed
    complex operator+(const complex& z) const {
         return complex{real_ + z.real(), image_ + z.image()};
        
         // the code below cannot be used
         // return *this += z;
    
        // because the own object (not its pointer) *this calls its operator += by passing z as reference
        // The problem is that the resulting sum is assignment in itself.
        // The function returns a copy of the summed object, but it is changed, a behavior does not desired
        // for this operator.
    }
    
    
    complex operator-(const complex& z) {
         return complex{real_ - z.real(), image_ - z.image()}; // another way
    }
    
    
    bool operator==(const complex& z) {
        return (real_ == z.real_) && (image_ == z.image_);
    }
    
    
    bool operator!=(const complex& z) {
        return !(*this == z); // it calls the overloaded operator ==
    }
    
    
    // implementation is in complex.cpp
    void print();
};


#endif //TOUR_CPP_COMPLEX_COMPLEX_H
