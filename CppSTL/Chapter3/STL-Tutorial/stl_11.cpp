// 4.3.1 section - Generic algorithms

#include <vector>
#include <list>
#include <iostream>

using namespace std;

const int* binary_search (const int* array, int n, int x) {   
	const int* lo = array, *hi = array + n, *mid;   
	while(lo != hi) {      
		mid = lo + (hi - lo) / 2;      
		if (x == *mid) 
			return mid;      
		if (x < *mid) 
			hi = mid; 
		else lo = mid + 1;   
	}   
	return 0;
}

int main ()
{
	 // array of ten integer values
	int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};     
	// value searched for
	int search_value = 3;

	cout<<"Addres for searched element: " << binary_search(x, 10, search_value);
	
	cout<< endl;
	
	cout<<"Searched element: " << *binary_search(x, 10, search_value);	
}