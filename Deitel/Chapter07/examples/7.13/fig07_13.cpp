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
#include <iomanip>
#include <iostream>

void modifyArray(int[], int);
void modifyElement(int);

int main(int argc, const char *argv[]) {
    const int arraySize = 5;
    int a[arraySize] = {0, 1, 2, 3, 4};

    std::cout << "Effects of passing entire array by reference:"
              << "\nThe values of the original array are:\n";

    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(3) << a[i];
    }

    std::cout << std::endl;

    // pass array a to modifyArray by reference
    modifyArray(a, arraySize);

    std::cout << "The values of the modified array are:\n";

    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(3) << a[i];
    }

    std::cout << "\n\nEffects of passing array element by value:"
              << "\na[3] before modifyElement: " << a[3] << std::endl;

    modifyElement(a[3]);

    std::cout << "a[3] after modifyElement: " << a[3] << std::endl;
    return 0;
}
// in function modifyArray, "b" points to the original array "a" in memory
void modifyArray(int b[], int sizeOfArray) {
    // multiply each array element by 2
    for (int k = 0; k < sizeOfArray; ++k) {
        b[k] *= 2;
    }
}
// in funciton modifyElement, "e" is a local copy of array element a[3] passed
// from main
void modifyElement(int e) {
    std::cout << "Value of element in modifyElement: " << (e *= 2) << std::endl;
}
