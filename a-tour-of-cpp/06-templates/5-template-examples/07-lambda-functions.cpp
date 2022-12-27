#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// Text based on the book: Stephen Prata, "C++ Primer Plus", 6th edition (2012), chapter 18; and
// Bjarne Stroustrup, "A Tour of C++", 2nd edition (2018).


int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    int
    
    // A lambda function can access/capture any automatic variable in its scope.
    
    // [] : capture nothing (no variable)
    auto print = [](const int& n) { cout << " " << n; };
    
    cout << "before: ";
    std::for_each(v.begin(), v.end(), print);     // for each applies the defined function (3rd argument)
                                                  // for all elements from a container for a given range
    cout << '\n';
    
    
    // increases each element of the vector
    // each element from the vector is passed as reference to the lambda function,
    // then it is incremented
    cout << "after:  ";
    std::for_each(v.begin(), v.end(), [](int& n) { n++; });
    std::for_each(v.begin(), v.end(), print);
    cout << "\n";
    
    
    return 0;
}

