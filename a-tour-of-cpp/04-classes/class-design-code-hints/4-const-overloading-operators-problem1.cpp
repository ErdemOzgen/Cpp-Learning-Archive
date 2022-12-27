#include <iostream>
#include <stdexcept>    // std::length_error
#include <algorithm>    // std::copy

//using std::cout, std::endl; // use of multiple declarations in a single using declaration is a C++17 feature
using std::cout;
using std::endl;


class Vector {
private:
    int size_ = 0;
    double *elem_ = nullptr;

public:
    Vector(std::initializer_list<double> lst)
            : elem_{new double[lst.size()]}, size_{static_cast<int>(lst.size())} {
        cout << "initializer-list constructor for Vector\n";
        
        std::copy(lst.begin(), lst.end(), elem_);
    }
    
    
    ~Vector() {
        delete[] elem_;
    }
    
    
    void print() const {
        cout << "size = " << size_ << endl;
        
        for (int i = 0; i < size_; i++)
            cout << "[" << i << "] = " << elem_[i] << "\n";
    }
    
    
    // Text based on the book: Scott Meyers, "Effective C++ (2005)", Itens 3)
    //
    // Overloading operations is a way to mimic conventional usage.
    // The operator[] aims to directly access the elements of the private data elem_,.
    // Thus, we can use it as a set function (v[0] = 10) or a get function (double x = v[0]).
    // However, this breaks the encapsulations and can be very dangereous.
    //
    // Problem: This overloaded operator does not work for `const` object
    // of Vector even if used as a get function (see function foo())
    double& operator[](int i) {
        return elem_[i];
    }
};


void foo(const Vector& v) {
    cout << "foo()\n";
    cout << "v[0] = " << v[0] << endl; // error: no viable overloaded operator[] for type 'const Vector'
}


int main() {
    Vector v {1.5, 2.5, 3.5};
    foo(v);
    
    return 0;
}
