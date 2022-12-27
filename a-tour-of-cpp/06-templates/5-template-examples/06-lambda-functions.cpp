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


int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // counting by Functor
    f_mod fmod2{2};
    int count2_by_functor = std::count_if(v.begin(), v.end(), fmod2);
    cout << "count2_by_functor = " << count2_by_functor << endl;
    
    // counting by Lambda Function: [](int x) {return x % 2 == 0;}
    int count2_by_lambda = std::count_if(v.begin(), v.end(), [](int x) {return x % 2 == 0;});
    cout << "count2_by_lambda = " << count2_by_lambda << endl << endl;
    
    
    // counts how many numbers are divisive by 3
    f_mod fmod3{3};
    int count3_by_functor = std::count_if(v.begin(), v.end(), fmod3);
    cout << "count3_by_functor = " << count3_by_functor << endl;
    
    int count3_by_lambda = std::count_if(v.begin(), v.end(), [](int x) {return x % 3 == 0;});
    cout << "count3_by_lambda = " << count3_by_lambda << endl << endl;
    
    
    // In terms of brevity, the functor code is more verbose than the equivalent function or lambda code.
    // Functions and lambdas are approximately equally brief.
    // One apparent exception would be if you had to use a lambda twice:
    int count5_by_lambda = std::count_if(v.begin(), v.end(), [](int x) {return x % 5 == 0;});
    int count5_by_lambda_again = std::count_if(v.begin(), v.end(), [](int x) {return x % 5 == 0;});
    cout << "count5_by_lambda = " << count5_by_lambda << endl;
    cout << "count5_by_lambda_again = " << count5_by_lambda_again << endl << endl;
    
    // But you don’t actually have to write out the lambda twice.
    // Essentially, you can create a name for the anonymous lambda and then use the name twice:
    auto lambda_mod7 = [](int x){return x % 7 == 0;}; // lambda_mod7 a name for the lambda
    
    int count7_by_lambda = std::count_if(v.begin(), v.end(), lambda_mod7);
    int count7_by_lambda_again = std::count_if(v.begin(), v.end(), lambda_mod7);
    cout << "count7_by_lambda = " << count7_by_lambda << endl;
    cout << "count7_by_lambda_again = " << count7_by_lambda_again << endl << endl;
    
    // Thus, we even can use this no-longer-anonymous lambda as an ordinary function:
    bool result = lambda_mod7(10); // result is true if 10 % 7 == 0
    
    
    // We still can use auto for the parameter datatypes, so that the lambda function becomes more generic
    // PS: it does not make sense for this problem, but it is just an example of how to use auto
    auto lambda_mod8 = [](auto x){ return x % 8 == 0; };
    
    
    // Unlike an ordinary function, however, a named lambda can be defined inside a function.
    // The actual type for lambda_mod7 will be some implementation-dependent type that the compiler uses
    // to keep track of lambdas.
    
    return 0;
}

