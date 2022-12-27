#include <iostream>

#include "vector.h"

using std::cout;
using std::endl;


int main() {
    cout << "### integer\n";
    Vector<int> vi{1, 2, 3};
    vi.print();
    cout << "--------------\n\n";

    cout << "### double\n";
    Vector<double> vd = {1.5, 2.5, 3.5};
    vd.print();
    cout << "--------------\n\n";

    cout << "### string\n";
    Vector<std::string> vs = {"zero", "one", "two"};
    vs.print();
    cout << "--------------\n\n";
    
    return 0;
}