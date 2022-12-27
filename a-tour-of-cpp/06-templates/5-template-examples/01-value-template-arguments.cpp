#include <iostream>


template <typename T, int N>
class Vector {
private:
    T *elem_;
    int size_;

public:
    Vector() {
        std::cout << "N = " << N << std::endl;
        size_ = N;
        elem_ = new T[N];
    }
    
    int size() const {
        return size_;
    }
};



int main() {
    Vector<int, 10> v;
    std::cout << "size = " << v.size() << std::endl;
    
    return 0;
}