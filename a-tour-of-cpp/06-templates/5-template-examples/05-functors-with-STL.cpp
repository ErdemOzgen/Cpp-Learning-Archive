#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// Codes based on the book: Stephen Prata, "C++ Primer Plus", 6th edition (2012), chapter 18


// A Functor whose operator() checks if a given X is divisive by a pre-defined divisor (defined in the constructor)
class f_mod {
private:
    int dv_;

public:
    f_mod(int dv = 1) : dv_{dv} {}
    
    // Is x divisive by dv_?
    bool operator()(int x) {
        return (x % dv_) == 0;
    }
};


// a specific function that checks if x is divisive by 5
bool f_mod5(int x) {
    return (x % 5) == 0;
}


int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // The STL `count_if` function applies a given function (3rd argument) to all elements
    // from a container, in a specific range (1st and 2nd arguments), and counts the number of
    // trues returned by the function.
    // We can use a specific function or a Functor
    
    // counts how many numbers are divisive by 2
    f_mod fmod2{2};
    int count2 = std::count_if(v.begin(), v.end(), fmod2);
    cout << "count2 = " << count2 << endl << endl;
    
    // counts how many numbers are divisive by 3
    f_mod fmod3{3};
    int count3 = std::count_if(v.begin(), v.end(), fmod3);
    cout << "count3 = " << count3 << endl << endl;
    
    // Counts how many numbers are divisive by 5
    // Note we are using a specific function to it.
    int count5 = std::count_if(v.begin(), v.end(), f_mod5);
    cout << "count5 = " << count5 << endl << endl;
    
    // PROBLEM:
    // Create a specific function for each possibility is impracticable.
    // Moreover, its definition can be located possibly quite far from its use.
    //
    // Functors can be pretty good because a class, including a functor class, can be defined inside a function,
    // so the definition can be located close to the point of use.
    // It is flexible as well.
    //
    // In terms of brevity, the functor code is more verbose: we have some code lines to define the class and
    // we have to correctly instantiate its objects.
    //
    // SOLUTION:
    // Since we only need to use a simple and flexible function for this example,
    // we could use lambda functions/expressions... see example: 6-lambda-functions1.cpp
    
    return 0;
}

