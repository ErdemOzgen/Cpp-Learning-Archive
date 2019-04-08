/*
 * =====================================================================================
 *
 *       Filename:  MergeSort.cpp
 *
 *    Description:  Fig. 19.06 - Class that creates a vector filled with random
 *                  integers. Provides a function to sort the vector with merge
 *                  sort.
 *
 *        Version:  1.0
 *        Created:  06/03/17 17:54:33
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "MergeSort.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

// constructor fill vector with random integers
MergeSort::MergeSort(int vectorSize) {
    size = (vectorSize > 0 ? vectorSize : 10);
    srand(time(0));

    for (int i = 0; i < size; ++i) data.push_back(10 + rand() % 90);
}
// split vector, sort subvectors and merge subvectors into sorted vector
void MergeSort::sort() {
    sortSubVector(0, size - 1);  // recursively sort entire vector
}
// recursive function to sort subvectors
void MergeSort::sortSubVector(int low, int high) {
    // test base case; size of vector == 1
    if ((high - low) >= 1) {
        int middle1 = (low + high) / 2;  // calculate middle of vector
        int middle2 = middle1 + 1;       // calculate next element over

        // output split step
        std::cout << "split:   ";
        displaySubVector(low, high);
        std::cout << std::endl << "        ";
        displaySubVector(low, middle1);
        std::cout << std::endl << "        ";
        displaySubVector(middle2, high);
        std::cout << std::endl << "        ";

        // split vector in half; sort each half (recursive calls)
        sortSubVector(low, middle1);
        sortSubVector(middle2, high);

        // merge two sorted vectors after split calls return
        merge(low, middle1, middle2, high);
    }
}
// merge two sorted subvectors into one sorted subvector
void MergeSort::merge(int left, int middle1, int middle2, int right) {
    int leftIndex = left;
    int rightIndex = middle2;
    int combinedIndex = left;
    std::vector<int> combined(size);

    // output two subvectors before merging
    std::cout << "merge:   ";
    displaySubVector(left, middle1);
    std::cout << std::endl << "          ";
    displaySubVector(middle2, right);
    std::cout << std::endl;

    // merge vectors until reaching the end of either
    while (leftIndex <= middle1 && rightIndex <= right) {
        // place smaller of two current elements into result
        // and move to next space in vector
        if (data[leftIndex] <= data[rightIndex])
            combined[combinedIndex++] = data[leftIndex++];
        else
            combined[combinedIndex++] = data[rightIndex++];
    }

    // if at end of left vector
    if (leftIndex == middle2) {
        // copy in remainder of right vector
        while (rightIndex <= right)
            combined[combinedIndex++] = data[rightIndex++];
    } else {  // at end of right vector
        while (leftIndex <= middle1)
            combined[combinedIndex++] = data[leftIndex++];
    }

    // copy values back into original vector
    for (int i = left; i <= right; ++i) data[i] = combined[i];

    // output merged vector
    std::cout << "         ";
    displaySubVector(left, right);
    std::cout << std::endl << std::endl;
}
// display elements in vector
void MergeSort::displayElements() const { displaySubVector(0, size - 1); }
// display certain values in vector
void MergeSort::displaySubVector(int low, int high) const {
    // output spaces for alignment
    for (int i = 0; i < low; ++i) std::cout << "   ";

    // output elements left in vector
    for (int i = low; i <= high; ++i) std::cout << " " << data[i];
}
