//Exercise 4.3.2: Write a generator object which can be used with the STL 
// algorithm generate (group 2) to fill containers with certain values. It should 
// be possible to specify a starting value and a step size, so that the first 
// element in the container is the starting value and every further element 
// is the sum of the preceding element and the step size. 

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
	vector<int> v(10);

	generate (v.begin(), v.end(), gen<vector<int>::value_type> (1, 2) );
			
	ostream_iterator<int> os(cout);

	copy (v.begin(), v.end(), os);
}
