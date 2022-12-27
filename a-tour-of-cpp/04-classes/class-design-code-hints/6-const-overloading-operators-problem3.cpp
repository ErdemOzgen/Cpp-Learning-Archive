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
    
    
    // SOLUTION: the same of example 3-solution-to-return-handles-to-object-internals.cpp
    // Add `const` to its return type
    // Now, this functions becomes read-only for const objects.
    // PROBLEM: non-const objects cannot modify the element anymore... and we really want to do that for this case
    // we have a compilaton error
    const double& operator[](int i) const {
        return elem_[i];
    }
};


void foo(const Vector& v) {
    cout << "foo()\n";
    cout << "v[0] = " << v[0] << endl; // getting the elements works fine for const objects
    // v[0] = 100.5; // not allowed... operator[] is read-only for const objects
}


int main() {
    cout << "v\n";
    Vector v {1.5, 2.5, 3.5};
    v.print();
    cout << endl;
    
    foo(v);
    // non-const objects cannot modify the elements anymore... we really want to do that
    // error: cannot assign to return value because function 'operator[]' returns a const value
    v[1] = 200.5;
    v[2] = 300.5;
    
    v.print();
    
    return 0;
}
