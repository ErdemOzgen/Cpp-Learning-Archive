// Exercise 4.3.1: Fill two containers with the same number of integer values. 
// Create a new container, whose elements are the sum of the appropriate 
// elements in the original container. Hint: The library provides an algorithm 
// and a function object to do the exercise. 

#define __MINMAX_DEFINED       

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <class value_type>
class gen {
	public:
		gen() : start(0), step(1) {}
		gen (value_type sta, value_type ste) : start(sta), step(ste) {}
		value_type operator() (void){ 
			value_type tmp = start; 
			start += step; 
			return tmp; 
		}
	private:
         value_type start, step;
};

int main ()
{
	vector<int> a;
	vector<int> b;

	for (int i = 0; i < 4; i++) {
		a.push_back (i*2); 
		b.push_back ((i+1)*3); 
	}

	vector<int> c(4);	// allocate memory for 4 int values!!

	// use the algo "transform" and the function object "plus"
	// transfrom takes the elements of vectors a and b, adds them using
	// plus and writes the results to c

	transform (a.begin(), a.end(), b.begin(), c.begin(), plus<int>() );
	
	ostream_iterator<int> os(cout);

	copy (c.begin(), c.end(), os);
}
