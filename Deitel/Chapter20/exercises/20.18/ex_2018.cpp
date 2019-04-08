/*
 * =====================================================================================
 *
 *       Filename:  ex_2018.cpp
 *
 *    Description:  Exercise 20.18 - Duplicate Elimination.
 *
 *        Version:  1.0
 *        Created:  18/07/17 14:55:31
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "Tree.hpp"

/**
 * removes duplicates in the given array.
 * @param arr.
 * @param SIZE.
 */
template<typename T>
void duplicateElimination(T arr[], size_t& SIZE) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = i + 1; j < SIZE;) {
            // duplicate found remove it and shift remaining values
            if (arr[i] == arr[j]) {
                for (unsigned int k = j; k < SIZE; ++k) {
                    arr[k] = arr[k + 1];
                }
                // reduce size
                --SIZE;
            } else {  // only increment if no match (consecutive duplicates)
                ++j;
            }
        }
    }
}  // end method duplicateElimination

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, const char* argv[]) {
    size_t LENGTH = 10;

    Tree<int> intTree;
    int intArr[LENGTH];

    std::cout << "Enter 10 integers (duplicates welcome): ";

    // insert 10 integers to intTree
    int intValue;
    for (unsigned int i = 0; i < LENGTH; ++i) {
        std::cin >> intValue;

        intTree.insertNode(intValue);

        intArr[i] = intValue;
    }

    std::cout << "Tree" << std::endl;
    intTree.inOrderTraversal();

    std::cout << "\n\nArray - Before elimination:" << std::endl;

    for (unsigned int i = 0; i < LENGTH; ++i) { printf("%d ", intArr[i]); }

    duplicateElimination(intArr, LENGTH);

    std::cout << "\nAfter elimination: " << std::endl;

    for (unsigned int i = 0; i < LENGTH; ++i) { printf("%d ", intArr[i]); }

    std::cout << std::endl;

    return 0;
}  // end method main
