#include <iostream>

using std::cout;
using std::endl;


int main() 
{
    // A simple array of numbers in the stack
    int nums[5] = {1, 2, 3, 4, 5};
    // A pointer in stack to use for accessing the above array
    int *p = nums;  // p points to first element of nums array, i.e. 1
    int counter=0;
    while(counter++ != sizeof(nums)/sizeof(int)) {
        // Check the addresses, each element has (int) size distance from another one
        //
        cout << "Nums[" << counter-1 << "] = " <<  *p << "\t address --> " << (int)p << "\n";
        // Since nums array is an array of integers, when p = p + 1
        // then p is not increasing by one, but it is moving to the next element,
        // i.e. it is increasing by the size of type of nums array
        p++;
    }

    // Make p point to nums 1st element again pleaser
    //
    p=nums;
    cout << "\nDistance between 1st and 2nd element is : " << (int)(p+1) - (int)p << endl;

    // Deallocate memory
    p = nullptr;
    delete []p;

    return 0;
}

/* Sample Output ::

Nums[0] = 1      address --> 6422260
Nums[1] = 2      address --> 6422264
Nums[2] = 3      address --> 6422268
Nums[3] = 4      address --> 6422272
Nums[4] = 5      address --> 6422276

Distance between 1st and 2nd element is : 4

*/