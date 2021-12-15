#include <optional>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

optional<double> square_root(double x)
{
    if (x < 0.0)
    	return nullopt;
    else
    	return sqrt(x);
}

int main(int argc, char** argv) 
{
    vector<double> v= {4.0, -4.0, -0.09, 0.25};
    for (double d : v) 
	if (auto s= square_root(d); s)
	    cout << "Square root of " << d << " is " << *s << '\n';
	else
	    cout << d << " has no square root.\n";
    return 0;
}
