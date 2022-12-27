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
    
    
    // Problem: This overloaded operator has the problem of "Returning Handles for Object Internals".
    // But, the main problem for this design in our container is: it can modify the i-th element of a `const` object.
    // see foo()
    double& operator[](int i) const {
        return elem_[i];
    }
};


void foo(const Vector& v) {
    cout << "foo()\n";
    cout << "v[0] = " << v[0] << endl; // getting the elements works fine for const objects
    v[0] = 100.5; // PROBLEM:: const object can modify its private member data!!!
    cout << "v[0] = " << v[0] << endl << endl;
}


int main() {
    cout << "v\n";
    Vector v {1.5, 2.5, 3.5};
    v.print();
    cout << endl;
    
    foo(v);
    // setting the elements in non-const object works perfectly...
    v[1] = 200.5;
    v[2] = 300.5;
    
    // foo() modified the [0]-element of the vector, even it has been passed as const.
    v.print();
    
    return 0;
}
