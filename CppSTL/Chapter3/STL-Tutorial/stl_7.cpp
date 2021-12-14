// 4.1.2 section - Exercises Vector

// Exercise 1: Write a STL program that declares a vector of integer values, 
// stores five arbitrary values in the vector and then prints the single vector elements to cout. 

#include <vector>
#include <iostream>

using namespace std;

int main ()
{
	// define a vector of int and reserve memory for five elements
	vector<int> v(5);             
    
	// store arbitrary values into v[0] to v[4]	
	for (int i = 0; i < 5; i++)
		v[i] = 2*i;                 
	
	cout << "Five values stored in a vector are written to cout:" << endl;

	for (int i = 0; i < 5; i++)
		cout << v[i] << "  ";       

	cout << endl;

	// of course you can also use iterators

	// define an iterator to the first vector element
	vector<int>::iterator first = v.begin();

	// define an iterator past the last vector element
	vector<int>::iterator last  = v.end();

	cout << "Now the output loop works with iterators:" << endl;

	while (first != last)
		// first the iterator is dereferenced and then it is incremented
		cout << *first++ << "  ";    
}