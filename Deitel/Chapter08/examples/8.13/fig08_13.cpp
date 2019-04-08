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

void selectionSort(int *const, const int);
void swap(int *const, int *const);

int main(int argc, const char *argv[]) {
    const int arraySize = 10;

    int a[arraySize] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    std::cout << "Data items in original order\n";

    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(4) << a[i];
    }

    // sort the array
    selectionSort(a, arraySize);

    std::cout << "\nData items in ascending order\n";

    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(4) << a[i];
    }

    std::cout << std::endl;

    return 0;
}
// function to sort an array
void selectionSort(int *const array, const int size) {
    int smallest;  // index of smallest element

    for (int i = 0; i < size - 1; ++i) {
        smallest = i;  // first index of remaining array

        // loop to find index of smallest element
        for (int index = i + 1; index < size; ++index) {
            if (array[index] < array[smallest]) { smallest = index; }
        }

        swap(&array[i], &array[smallest]);
    }
}
// swap valus at memory locations to which element1Ptr and element2Ptr point
void swap(int *const element1Ptr, int *const element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}
