// Include STL library
#include <vector>
#include <iostream>

using namespace std;

template<class RandomAccessIterator, class T>RandomAccessIterator binary_search (RandomAccessIterator first, RandomAccessIterator last, const T& value) {   
	RandomAccessIterator not_found = last, mid;   
	while(first != last) {      
		mid = first + (last - first) / 2;      
		if (value == *mid) 
			return mid;      
		if (value < *mid) 
			last = mid; 
		else first = mid + 1;   
	}   
	return not_found;
}

int main (){
	// define number of elements
	int n = 5;

	// define vector
	int v[] = {1,2,3,4,5};
	
	// search for element
	for(int i = 0; i < n; i++){
		int* ok = binary_search (&v[0], &v[n], v[i]);
		if (ok == &v[n]) 
			cout << "value '"<< v[i] <<  " not found\n"; 
		else 
			cout << "value '"<< v[i] <<  " found\n"; 
	}
	
	return 0;
}