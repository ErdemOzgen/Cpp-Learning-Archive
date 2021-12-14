#include <iostream>

using namespace std;

void squares(int *nums, int sz) 
{   
    int counter{0};
    while(counter++ != sz) {
        *nums *= *nums;
        nums++;
    }
}

void print(int *arr, int sz) 
{
    int i=0;
    while(i++ != sz) {
        cout << *arr << " ";
        arr++;
    }
    cout << endl;
}


int main()
{
    const int N = 5;
    int nums[N] = {1,2,3,4,5};
    
    // Call the void func to ^2 every element of the nums array
    // 
    squares(nums, N);
    
    // Declare a pointer to a function
    //
    void (*func_ptr)(int *, int);
    // Initialize the above pointer
    // Now, the function pointer points to the print() function
    //
    func_ptr = print;

    // Call the function pointer that points to the print() function 
    // with the appropriate parameters
    //
    (*func_ptr)(nums, N);

    return 0;
}

/* Sample Output ::

$ g++ function_pointer.cpp -o main
$ ./main.exe
1 4 9 16 25

*/