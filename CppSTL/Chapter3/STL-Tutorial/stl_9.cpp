// 4.2.2 section - Forward Iterator

#include <vector>
#include <list>
#include <iostream>

using namespace std;

template<class ForwardIterator, class T> ForwardIterator find_linear (ForwardIterator first, ForwardIterator last, T value) {   
	// We check each element
	while (first != last) {
		// If we find it, we return the address
		if (*first == value) 
			return first;   
		// Go to the next element
		first++;
		}
		return last;
}

int main ()
{
	vector<int> v (3, 1);
	
	v.push_back (7);  // vector v: 1 1 1 7
	
	vector<int>::iterator i = find_linear (v.begin(), v.end(), 7);
	
	if (i != v.end() ) 
		cout << "found: " << *i; 
	else 
		cout << "not found";
	
	cout << endl;
	
	vector<int>::iterator j = find_linear (v.begin(), v.end(), 9);
	
	if (j != v.end() ) 
		cout << "found: " << *j; 
	else 
		cout << "not found";
	
	cout << endl;
}