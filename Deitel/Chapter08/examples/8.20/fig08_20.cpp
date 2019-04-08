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

void selectionSort(int[], const int, bool (*)(int, int));
void swap(int *const, int *const);
bool ascending(int, int);
bool descending(int, int);

int main(int argc, const char *argv[]) {
    const int arraySize = 10;

    int order;  // 1 = ascending 2 = descending
    int a[arraySize] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    std::cout << "Enter 1 to sort in ascending order.\n"
              << "Enter 2 to sort in descending order: ";
    std::cin >> order;

    // output original array
    std::cout << "\nData items in original order\n";

    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(4) << a[i];
    }

    // sort array in ascending order; pass function ascending as an argument
    // to specify ascending sorting order
    if (order == 1) {
        selectionSort(a, arraySize, ascending);
        std::cout << "\nData items in ascending order\n";
        // sort array in descending order; pass function descending as an
        // argument
        // to specify descending sort order
    } else {
        selectionSort(a, arraySize, descending);
        std::cout << "\nData items in descending order\n";
    }

    // output sorted array
    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(4) << a[i];
    }

    std::cout << std::endl;
    return 0;
}
// multipurpose selection sort; the parameter compare is a pointer to the
// comparison function that determines the sorting order
void selectionSort(int work[], const int size, bool (*compare)(int, int)) {
    int smallestOrLargest;  // index of smallest or largest element

    for (int i = 0; i < size - 1; ++i) {
        smallestOrLargest = i;  // first index of remaining vector

        for (int index = i + 1; index < size; ++index) {
            if (!(*compare)(work[smallestOrLargest], work[index])) {
                smallestOrLargest = index;
            }
        }
        swap(&work[smallestOrLargest], &work[i]);
    }
}
// swap values at memory locations to which element1Ptr and element2Ptr point
void swap(int *const element1Ptr, int *const element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}
// detemine whether a is less than b for an ascending order sort
bool ascending(int a, int b) { return a < b; }
// determine whether a is greater than b for a descending order sort
bool descending(int a, int b) { return a > b; }
