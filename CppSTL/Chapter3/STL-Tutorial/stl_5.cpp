// 4.1.1 section - Vector
#include <vector>
#include <iostream>

using namespace std;

int main (){  
	// Define a vector using the default constructor 
	vector<int> v;
	// Get the capacity of the vector 
	// Capacity = how many items can be fit in the vector before it is "full". Once full, adding new items will result in a new, larger block of memory being allocated and the existing items being copied to it.
	vector<int>::size_type v_capacity = v.capacity();
	// Get the size of the vector 
	// Size = the number of items currently in the vector
	vector<int>::size_type v_size = v.size();
	cout << "Capacity: " << v_capacity <<"\n";
	cout << "Size: " << v_size <<"\n";
	
	// Define a vector and we specify a number that tells the vector for howmany elements memory should be allocated
	vector<int> w (5);
	vector<int>::size_type w_capacity = w.capacity();
	vector<int>::size_type w_size = w.size();
	cout << "Capacity: " << w_capacity <<"\n";
	cout << "Size: " << w_size <<"\n";
	// Add elements
	for(int i = 0; i < w_size; i++){
		w[i] = i;
	}
	// Print vector
	for(int i = 0; i < w_size; i++)
		cout << w[i] << " ";
}