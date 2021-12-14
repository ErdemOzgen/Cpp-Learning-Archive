// Include STL library
#include <vector>
#include <iostream>

using namespace std;

int main (){  
	// Define a vector with 5 elements
	vector<int> v(5);  
	// Define the value for each element
	v[0] = 0;  
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	v[4] = 4;
	// Print elements of the vector
	for (int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	return 0;
}