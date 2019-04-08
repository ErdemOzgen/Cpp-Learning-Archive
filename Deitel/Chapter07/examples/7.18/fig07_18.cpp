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

int linearSearch(const int[], int, int);

int main(int argc, const char *argv[]) {
    const int arraySize = 100;
    int a[arraySize];
    int searchKey;

    for (int i = 0; i < arraySize; ++i) {
        a[i] = 2 * i;
    }

    std::cout << "Enter integer search key: ";
    std::cin >> searchKey;

    // attempt to locate searchKey in array a
    int element = linearSearch(a, searchKey, arraySize);

    // display results
    if (element != -1) {
        std::cout << "Found value in element " << element << std::endl;
    } else {
        std::cout << "Value not found" << std::endl;
    }

    return 0;
}
// compare key to every element of array until location is found or until end of
// array is reached; return subscript of element if key is found or -1 if key is
// not found
int linearSearch(const int array[], int key, int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; ++i) {
        if (array[i] == key) { return i; }
    }

    return -1;
}
