/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#include <iostream>
#include <new>  // bad_alloc class is defined here

int main(int argc, const char *argv[]) {
    double *ptr[50];

    // aim each ptr[i] at a big block of memory
    try {
        // allocate memory for ptr[i]; new throw bad_alloc on failure
        for (int i = 0; i < 50; ++i) {
            ptr[i] = new double[50000000];  // may throw exception
            std::cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
        }
    } catch (std::bad_alloc &memoryAllocationExeption) {
        std::cerr << "Exception occured: " << memoryAllocationExeption.what()
                  << std::endl;
    }
    return 0;
}
