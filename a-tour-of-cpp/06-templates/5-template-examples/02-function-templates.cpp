#include <iostream>


template <typename T>
class Vector {
private:
    T *elem_;
    int size_;

public:
    Vector(std::initializer_list<T> lst)
            : elem_{new T[lst.size()]}, size_{static_cast<int>(lst.size())} {
        std::copy(lst.begin(), lst.end(), elem_); // copy from lst into elem (§12.6)
    }
    
    void print() {
        std::cout << "size = " << size_ << std::endl;
        
        for (int i = 0; i < size_; i++)
            std::cout << "[" << i << "] = " << elem_[i] << "\n";
        std::cout << "\n";
    }
    
    T* begin() {
        return size_ ? &elem_[0] : nullptr; // pointer to first element or nullptr
    }
    
    T* end() {
        return size_ ? &elem_[size_] : nullptr; // pointer to one-past-last element (next address after the last element)
    }
};


// Container should be a container with range-for implemented
// The Value template argument and the function argument v are there to allow
// the caller to specify the type and initial value of the accumulator (the variable in which to accumulate the sum):
// Note that when callind sum, a copy is passed to v, not its reference. Then, we can edit v without changing its
// original value out of the function.
template<typename Container, typename Value>
Value sum(const Container& s, Value v) {
    for (const auto x : s)
        v += x;
    return v;
}


int main() {
    std::cout << "v1\n";
    Vector<int> v1 {1, 2, 3};
    int sum_v1 = sum(v1, 0);
    std::cout << "sum = " << sum_v1 << "\n\n";
    
    
    return 0;
}