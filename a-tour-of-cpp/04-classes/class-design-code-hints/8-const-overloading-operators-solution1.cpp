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
    
    
    // Removing Code Duplication
    // SOLUTION (based on the book: Scott Meyers, "Effective C++ (2005)", Itens 3)
    // Let the codes in the const operator and call it from the non-const operator
    // All keeps working fine!!!
    const double& operator[](int i) const { // for const objects
        return elem_[i];
    }
    
    // To call the const operator, we have to become the current object as const, and
    // then remove the resulting const reference (double& for this case) from the const operator.
    // We let this code/call in different lines to make the explanation easier.
    // The numbers inside the comments indicates the order of the explanation.
    double& operator[](int i) { // for non-const objects
        
        return                                     // 4. here, we return a double&
                const_cast<double&>(               // 3. const_cast removes the const from the resulting const double& of the const operator function.
                 static_cast<const Vector&>(*this) // 1. convert the current non-const object Vector to a const object Vector
                 [i]                               // 2. we now have a const object Vector calling its operator [i] - this call the const operator function
                );
    }
    
    
    // Excerpt from the book: Scott Meyers, "Effective C++ (2005)", Itens 27
    // C++ also offers four new cast forms (often called new-style or C++-style casts):
    // ■ const_cast<T>(expression)
    // ■ dynamic_cast<T>(expression)
    // ■ reinterpret_cast<T>(expression)
    // ■ static_cast<T>(expression)

    // Each serves a distinct purpose:
    // ■ const_cast is typically used to cast away the constness of objects. It is the only C++-style cast that can do this.
    // ■ dynamic_cast is primarily used to perform “safe downcasting,” i.e., to determine whether an object is of a particular type in an inher- itance hierarchy. It is the only cast that cannot be performed us- ing the old-style syntax. It is also the only cast that may have a significant runtime cost. (I’ll provide details on this a bit later.)
    // ■ reinterpret_cast is intended for low-level casts that yield implemen- tation-dependent (i.e., unportable) results, e.g., casting a pointer to an int. Such casts should be rare outside low-level code. I use it only once in this book, and that’s only when discussing how you might write a debugging allocator for raw memory (see Item 50).
    // ■ static_cast can be used to force implicit conversions (e.g., non-const object to const object (as in Item 3), int to double, etc.). It can also be used to perform the reverse of many such conversions (e.g., void* pointers to typed pointers, pointer-to-base to pointer-to-derived), though it cannot cast from const to non-const objects. (Only const_cast can do that.)
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
    // setting and getting work fine for non-const objects!!!
    v[1] = 200.5;
    v[2] = 300.5;
    
    v.print();
    
    return 0;
}
