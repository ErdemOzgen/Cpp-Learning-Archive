
#include <iostream>
#include <iostream>     // std::cerr
#include <stdexcept>    // std::length_error
#include <algorithm>    // std::copy


class Vector {
private:
    // default member initialization
    long size_ = 0;
    double *elem_ = nullptr;

public:
    Vector() {
        std::cout << "default constructor for Vector\n";
    }
    
    // constructor: establish invariant (pre-conditions), acquire resources (e.g., allocations on heap)
    explicit Vector(long size) {
        std::cout << "ordinary constructor for Vector\n";
        
        if (size < 0) {
            throw std::length_error{"Vector constructor: negative size"};
        }
        
        size_ = size;
        elem_ = new double[size];
        for (long i = 0; i < size_; i++)
            elem_[i] = 0;
    }
    
    
    Vector(std::initializer_list<double> lst)
            : elem_{new double[lst.size()]}, size_{static_cast<int>(lst.size())} {
        std::cout << "initializer-list constructor for Vector\n";
    
        std::copy(lst.begin(), lst.end(), elem_); // copy from lst into elem (§12.6)
    }
    
    
    // destructor: release resources
    ~Vector() {
        std::cout << "Vector destructor\n";
        delete[] elem_;
    }
    
    
    long size() const {
        return size_;
    }
    
    void print() {
        std::cout << "size = " << size() << std::endl;
        for (long i = 0; i < size(); i++)
            std::cout << "[" << i << "] = " << elem_[i] << std::endl;
        std::cout << "\n";
    }
    
    
    
    // copy constructor
    Vector(const Vector& v) : elem_{new double[v.size_]}, size_{v.size_} {
        std::cout << "Copy Constructor for Vector\n";
    
        for (int i = 0; i != v.size_; i++) // copy elements
            elem_[i] = v.elem_[i];
    }
    
    
    // copy assignment
    Vector& operator=(const Vector& v) {
        std::cout << "Copy Assignment for Vector\n";
    
        double* p = new double[v.size_];
    
        for (int i = 0; i != v.size_; i++) // copy elements
            p[i] = v.elem_[i];
        
        delete[] elem_; // delete old elements from the this/current object
        
        elem_ = p;
        size_ = v.size_;
    
        return *this;
    }
};



Vector foo() {
    return Vector{10, 20, 30};
}


int main() {
    std::cout << "V1\n";
    Vector v1 = {0, 1, 2, 3, 4}; // it calls the initializer-list constructor
    v1.print();
    
    std::cout << "V2\n";
    Vector v2 = v1; // it calls the Copy Constructor
    v2.print();
    
    std::cout << "V3\n";
    Vector v3 = foo(); // the initializer-list constructor is called inside the functions foo(),
                       // but no new construction is called for v3
    v3.print();
    
    std::cout << "V4\n";
    Vector v4; // it calls the default constructor
    v4 = v3;  // it calls the Copy Assignment
    v4.print();
    
    return 0;
}
