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

int main(int argc, const char *argv[]) {
    const int arraySize = 10;
    int data[arraySize] = {34, 56, 4, 10, 77, 51, 93, 30, 5, 52};
    int insert;  // temporary variable to old element to insert

    std::cout << "Unsorted array:\n";

    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(4) << data[i];
    }

    // insertion sort
    for (int next = 1; next < arraySize; ++next) {
        insert = data[next];  // store the value in the current element

        int moveItem = next;  // initialise location to place element

        // search for the location in which to put the current element
        while ((moveItem > 0) && (data[moveItem - 1] > insert)) {
            // shift element one slot to the right
            data[moveItem] = data[moveItem - 1];
            moveItem--;
        }

        data[moveItem] = insert;  // place inserted element into array
    }

    std::cout << "\nSorted array:\n";

    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(4) << data[i];
    }

    std::cout << std::endl;

    return 0;
}
