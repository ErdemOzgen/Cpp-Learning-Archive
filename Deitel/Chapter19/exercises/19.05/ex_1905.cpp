/*
 * =====================================================================================
 *
 *       Filename:  ex_1905.cpp
 *
 *    Description:  Exercise 19.05 - Bubble Sort
 *
 *        Version:  1.1
 *        Created:  08/03/17 17:31:58
 *       Revision:  19/02/18 13:39:42
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <random>

// print a vector
template <typename T>
void printVector(const std::vector<T>& data) {
    for (T elem : data) { std::cout << elem << " "; }
    std::cout << std::endl;
}

void bubbleSort(std::vector<int>&);

int main(int argc, const char* argv[]) {
    const size_t limit = 100;
    const size_t vecSize = 20;
    std::vector<int> intVec;

    std::random_device rd;
    std::mt19937 gen(rd());

    // randomise elements of intVec
    for (size_t i = 0; i < vecSize; ++i) {
        intVec.push_back(std::uniform_int_distribution<int>{0, limit}(gen));
    }

    std::cout << "\nBefore sorting:" << std::endl;
    printVector(intVec);

    bubbleSort(intVec);

    std::cout << "\nAfter Sorting:" << std::endl;
    printVector(intVec);

    return 0;
}

// bubble sort vector
void bubbleSort(std::vector<int>& intVec) {
    size_t size = intVec.size();

    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            // reverse comparison for reverse ordered sorting
            if (intVec[j] > intVec[j + 1]) {
                int tmp = intVec[j];

                intVec[j] = intVec[j + 1];
                intVec[j + 1] = tmp;
            }
        }
    }
}
