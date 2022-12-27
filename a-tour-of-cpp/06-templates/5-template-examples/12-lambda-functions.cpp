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
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "vector: ";
    print_vector(v);
    
    // We can explicitly indicate the datatype of the return, thus ignoring its automatic type deduction.
    // Just use the new trailing-return-value syntax: -> datatype
    //
    // This can be interesting for cases with possible different types for return, or even
    // for readability.
    int count_pairs = std::count_if(v.begin(), v.end(), [](const int& x) -> bool {
        return x % 2 == 0;
    });
    cout << "Number of Even elements = " << count_pairs << "\n";
    
    return 0;
}

