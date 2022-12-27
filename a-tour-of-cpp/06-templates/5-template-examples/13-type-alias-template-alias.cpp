#include <iostream>


// Type Alias Declaration in C++
// There is no difference between a type alias declaration and typedef declaration.
using uint = unsigned int;


template<typename T>
class Vector {
public:
    using value_type = T; // Alias for the class Template T
    
    void print(value_type x) {
        std::cout << "x = " << x << "\n";
    }
    
    // ...
};


template <typename Key, typename Value>
class Map {
private:
    Key key_;
    Value value_;
};


// Alias Template
template<typename Value>
using StringMap = Map<std::string, Value>;


int main() {
    Vector<int> v;
    v.print(10);
    
    StringMap<int> m; // m is a Map<std::string, int>
    
    
    return 0;
}
