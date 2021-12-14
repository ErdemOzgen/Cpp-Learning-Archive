// C++ program for illustration 
// of std::allocator() function 
#include <iostream> 
#include <memory> 
#include <string> 

using namespace std; 
  
int main() 
{ 
  
    // allocator for string values 
    allocator<string> myAllocator; 
  
    // allocate space for three strings 
    string* str = myAllocator.allocate(3); 
  
    // construct these 3 strings 
    myAllocator.construct(str, "Geeks"); 
    myAllocator.construct(str + 1, "for"); 
    myAllocator.construct(str + 2, "Geeks"); 
  
    cout << str[0] << str[1] << str[2]; 
  
    // destroy these 3 strings 
    myAllocator.destroy(str); 
    myAllocator.destroy(str + 1); 
    myAllocator.destroy(str + 2); 
  
    // deallocate space for 3 strings 
    myAllocator.deallocate(str, 3); 
} 

