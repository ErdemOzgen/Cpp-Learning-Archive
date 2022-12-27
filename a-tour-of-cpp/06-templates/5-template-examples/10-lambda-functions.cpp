#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// Text based on the book: Stephen Prata, "C++ Primer Plus", 6th edition (2012), chapter 18; and
// Bjarne Stroustrup, "A Tour of C++", 2nd edition (2018).


void print_vector(const std::vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << "\n";
}



int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    // A lambda function can access/capture any automatic variable in its scope.
    
    cout << "vector of x values\n";
    print_vector(v);
    
    double slope = 2.0;
    int y0 = 10;
    double sum_y = 0;
    
    cout << "resulting y values (" << y0 << " + (x * " << slope << "))\n";
    std::for_each(v.begin(), v.end(), [=](const int& x) { cout << " " << y0 + (x * slope); });
    cout << "\n";
    
    // We can combine =, &, name lists
    // slope and y0 are automatically passed by value, and sum_y is passed by reference
    std::for_each(v.begin(), v.end(), [=, &sum_y](const int& x) { sum_y += (y0 + (x * slope)); });
    cout << "sum_y = " << sum_y << "\n";
    
    // shift is passed by value, sum is passed by reference
    int shift = 10;
    int sum = 0;
    std::for_each(v.begin(), v.end(), [shift, &sum](const int& x) { sum += (x + shift); });
    cout << "sum (after shifting of 10) = " << sum << "\n";
    
    return 0;
}

