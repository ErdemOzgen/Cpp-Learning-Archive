/*
 * =====================================================================================
 *
 *       Filename:  BinarySearch.h
 *
 *    Description:  Fig. 19.02 - Class that contains a vector of random integers
 *                  and a function that uses binary search to find an integer.
 *
 *        Version:  1.0
 *        Created:  06/03/17 17:12:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include <vector>

class BinarySearch {
 public:
    BinarySearch(int);             // constructor initialises vector
    int binarySearch(int) const;   // perform a binary search on vector
    void displayElements() const;  // display vector elements

 private:
    int size;
    std::vector<int> data;

    void displaySubElements(int, int) const;  // display range of values
};
