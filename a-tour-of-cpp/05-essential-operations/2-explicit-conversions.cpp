
#include <iostream>


class Vector {
private:
    // default member initialization
    long size_ = 0;
    double *elem_ = nullptr;

public:
    explicit Vector(long size) {
        std::cout << "ordinary Vector constructor for input long\n";
        
        size_ = size;
        elem_ = new double[size];
        for (long i = 0; i < size_; i++)
            elem_[i] = 0;
    }
    
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
};


int main() {
    Vector v = 5; // this works: it calls the ordinary Vector constructor... but this is dangerous
    v.print();
    
    // to solve this problem, just add the keyword 'explicit' before the Vector constructor
    // explicit Vector(long size) { ... }
    
    // now, that assignment will raise a compilation error: no viable conversion from 'long' to Vector
    
    return 0;
}
