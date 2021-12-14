// 4.1.1 section - Vector
#include <vector>
#include <iostream>

using namespace std;

int main (){  
	// Define a vector using the default constructor 
	vector<int> v(3);
	
	v[0] = 5;
	v[1] = 2;
	v[2] = 7;
	
	// Iterator to the first element
	vector<int>::iterator first = v.begin();
	// Iterator to past the last element - if we dereference it we get undefined
	vector<int>::iterator last  = v.end();
	
	while (first != last)   
		cout << *first++ << " ";
}