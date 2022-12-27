// Example of Function Template


#include <iostream>
#include <list>   // STL list
#include <vector> // STL vector

// it uses the vector defined in other project
#include "../a-more-robust-vector/vector.h"

using std::cout;
using std::endl;


// FUNCTION TEMPLATE
//
// This sum() is a simplified version of the standard-library accumulate()
// For a given container cont, this functions sums all of its values
// based on an initial value v of the datatype Value.
// The resulting sum has the datatype Value.
//
// Note that we use the parameter v (initial value) as our accumulator. This is not a problem,
// because v is passed by value (a copy is done), no references/pointers are passed to it.
//
// The typenames Container and Value were chosen by us. They could have any other names.
template<typename Container, typename Value>
Value sum(const Container& cont, Value v) {
    for (const auto x : cont)
        v += x;
    return v;
}



int main() {
    // Note that a range-for is performed inside function sum()
    // This only works because we defined the functions begin() and end() for non-const and const objects.
    Vector<int> vi{1, 2, 7};
    cout << "sum(vi, 0) = " << sum(vi, 0) << "\n\n";
    
    Vector<double> vd{2.5, 4.5, 3.0};
    cout << "sum(vd, 0.0) = " << sum(vd, 0.0) << "\n\n";

    std::vector<int> vstl = {3, 5, 2};
    cout << "sum(vstl, 0) = " << sum(vstl, 0) << "\n\n";
    
    std::list<double> lstl = {1.2, 1.8, 7.0};
    cout << "sum(lstl, 0.0) = " << sum(lstl, 0.0) << "\n";
    
    return 0;
}

