/*
 * =====================================================================================
 *
 *       Filename:  BinarySearch.cpp
 *
 *    Description:  Fig. 19.03 - Class that contains a vector of random integers
 *                  and a function that uses binary search to find an integer.
 *
 *        Version:  1.0
 *        Created:  06/03/17 17:13:06
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "BinarySearch.hpp"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

// constructor initialises vector with random ints and sorts the vector
BinarySearch::BinarySearch(int vectorSize) {
    size = (vectorSize > 0 ? vectorSize : 10);  // validate vectorSize
    srand(time(0));

    // fill vector with random ints in range 10-99
    for (int i = 0; i < size; ++i) data.push_back(10 + rand() % 90);  // 10-99

    std::sort(data.begin(), data.end());
}
// perform a binary search on the data
int BinarySearch::binarySearch(int searchElement) const {
    int low = 0;
    int high = size - 1;
    int middle = (low + high + 1) / 2;
    int location = -1;

    do {
        // print remaining elements of vector to be searched
        displaySubElements(low, high);

        // output spaces for alignment
        for (int i = 0; i < middle; ++i) std::cout << "  ";

        std::cout << " * " << std::endl;  // indicate current middle

        // if the element is found at the middle
        if (searchElement == data[middle])
            location = middle;
        else if (searchElement < data[middle])
            high = middle - 1;
        else
            low = middle + 1;

        middle = (low + high + 1) / 2;  // recalculate the middle
    } while ((low <= high) && (location == -1));

    return location;
}
// display values in vector
void BinarySearch::displayElements() const { displaySubElements(0, size - 1); }
// display certain values in vector
void BinarySearch::displaySubElements(int low, int high) const {
    // output alignment spaces
    for (int i = 0; i < low; ++i) std::cout << "  ";

    // output elements left in vector
    for (int i = low; i <= high; ++i) std::cout << data[i] << " ";

    std::cout << std::endl;
}
