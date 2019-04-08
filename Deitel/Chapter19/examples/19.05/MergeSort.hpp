/*
 * =====================================================================================
 *
 *       Filename:  MergeSort.h
 *
 *    Description:  Fig. 19.05 - Class that creates a vector filled with random
 *                  integers. Provides a function to sort the vector with merge
 *                  sort.
 *
 *        Version:  1.0
 *        Created:  06/03/17 17:53:47
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

class MergeSort {
 public:
    explicit MergeSort(int);

    void sort();
    void displayElements() const;

 private:
    int size;
    std::vector<int> data;

    void sortSubVector(int, int);
    void merge(int, int, int, int);
    void displaySubVector(int, int) const;
};
