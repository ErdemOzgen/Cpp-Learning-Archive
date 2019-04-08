/*
 * =====================================================================================
 *
 *       Filename:  fig19_07.cpp
 *
 *    Description:  Fig. 19.07 - MergeSort test program.
 *
 *        Version:  1.0
 *        Created:  06/03/17 18:12:17
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "MergeSort.hpp"

#include <iostream>

int main(int argc, const char* argv[]) {
    MergeSort sortVector(10);

    std::cout << "Unsorted Vector:" << std::endl;
    sortVector.displayElements();  // print unsorted vector
    std::cout << std::endl << std::endl;

    sortVector.sort();

    std::cout << "Sorted vector:" << std::endl;
    sortVector.displayElements();  // print sorted vector
    std::cout << std::endl;

    return 0;
}
