// C++ program for illustration 
// of std::allocator() function 
#include <iostream> 
#include <memory> 

using namespace std; 

int main() 
{ 
  
    // allocator for integer values 
    allocator<int> myAllocator; 
  
    // allocate space for five ints 
    int* arr = myAllocator.allocate(5); 
  
    // construct arr[0] and arr[3] 
    myAllocator.construct(arr, 100); 
    arr[3] = 10; 
  
    cout << arr[0] << endl; 
	cout << arr[3] << endl; 
  
    // deallocate space for five ints 
    myAllocator.deallocate(arr, 5); 
  
    return 0; 
} 
