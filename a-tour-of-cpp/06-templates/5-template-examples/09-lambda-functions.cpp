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
    
    int sum = 0;
    int mult = 1;
    
    // A lambda function can access/capture any automatic variable in its scope.
    
    cout << "vector of x values\n";
    print_vector(v);
    
    // [&] : capture all local names used in the lambda function by reference
    std::for_each(v.begin(), v.end(), [&](const int& x) { sum += x; mult *= x; });
    cout << "sum = " << sum << "\n";
    cout << "mult = " << mult << "\n";
    
    // [&name1, &name2, ...] : capture the variables name1, name2, ... by reference
    sum = 0;
    mult = 1;
    std::for_each(v.begin(), v.end(), [&sum, &mult](const int& x) { sum += x; mult *= x; });
    cout << "sum = " << sum << "\n";
    cout << "mult = " << mult << "\n";
    
    
    return 0;
}

