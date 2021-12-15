
#include <iostream>


class value
{
public:
    explicit value(double x) : x{x} {}
    friend std::ostream& operator<<(std::ostream& os, value v) { return os << v.x; }
//     double operator<=>(value v2) { // doesn't generate == and !=
//         return x - v2.x;
//     }
    // double operator<=>(const value& v2) const = default; // compiler error in gcc 10
    auto operator<=>(const value& v2) const = default;
private:
    double x;
};



int main()
{
    using namespace std;
    
    value x{3}, y{5};
    
    cout << "x < y: " << boolalpha << (x < y) << endl;
    cout << "x > y: " << boolalpha << (x > y) << endl;
    cout << "x >= y: " << boolalpha << (x >= y) << endl;
    cout << "x <= y: " << boolalpha << (x <= y) << endl;
    
    cout << "x == y: " << boolalpha << (x == y) << endl;
    cout << "x != y: " << boolalpha << (x != y) << endl;
}
