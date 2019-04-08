/*
 * =====================================================================================
 *
 *       Filename:  ex_1910.cpp
 *
 *    Description:  Exercise 19.10 - Quicksort
 *
 *        Version:  1.0
 *        Created:  10/03/17 17:48:08
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <utility>
#include <random>

template <typename T>
void printVector(const std::vector<T>& data) {
    for (T elem : data) { std::cout << elem << " "; }

    std::cout << std::endl;
}

void quickSortHelper(std::vector<int>&, int, int);
int partition(std::vector<int>&, int, int);

int main(int argc, const char* argv[]) {
    const int limit = 100;
    const int size = 100;
    std::vector<int> intVec;

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < size; ++i) {
        intVec.push_back(std::uniform_int_distribution<int>{1, limit}(gen));
    }

    std::cout << "Unsorted Vector:\n";
    printVector(intVec);

    quickSortHelper(intVec, 0, (intVec.size() - 1));

    std::cout << "\nAfter Sorting:\n";
    printVector(intVec);

    return 0;
}
// Recursive quick sort
void quickSortHelper(std::vector<int>& intVec, int left, int right) {
    int index = partition(intVec, left, right);

    if (left < index - 1) { quickSortHelper(intVec, left, index - 1); }
    if (index < right) { quickSortHelper(intVec, index, right); }
}
// partition
int partition(std::vector<int>& intVec, int left, int right) {
    // pick pivot in middle of vector
    int pivot = intVec[(left + right) / 2];

    while (left <= right) {
        // find element on the left
        // that should be on right
        while (intVec[left] < pivot) { ++left; }

        // find element on right
        // that should be on left
        while (intVec[right] > pivot) { --right; }

        if (left <= right) {
            std::swap(intVec[left], intVec[right]);
            ++left;
            --right;
        }
    }
    return left;
}
