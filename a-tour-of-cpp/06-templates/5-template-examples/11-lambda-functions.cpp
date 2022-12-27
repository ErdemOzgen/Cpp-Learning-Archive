#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// Text based on the book: Stephen Prata, "C++ Primer Plus", 6th edition (2012), chapter 18; and
// Bjarne Stroustrup, "A Tour of C++", 2nd edition (2018).


void print_vector(const std::vector<double> v) {
    for (int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << "\n";
}



int main() {
    std::vector<double> vx = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> vy(vx.size());
    cout << "vx.size() = " << vx.size() << "\n";
    
    // A lambda function can access/capture any automatic variable in its scope.
    
    cout << "x values\n";
    print_vector(vx);

    double slope = 2.0;
    int y0 = 10;
    int i = 0;
    
    cout << "y values (" << y0 << " + (x * " << slope << "))\n";
    std::for_each(vx.begin(), vx.end(), [=, &i, &vy](const double& x) {
        vy[i] = y0 + (x * slope);
        cout << " " << vy[i];
        i++;
    });
    
    cout << "\ny values\n";
    print_vector(vy);
    
    
    return 0;
}

