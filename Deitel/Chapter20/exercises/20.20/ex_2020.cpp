/*
 * =====================================================================================
 *
 *       Filename:  ex_2020.cpp
 *
 *    Description:  Exercise 20.20 - Recursively Print a List Backward.
 *
 *        Version:  1.0
 *        Created:  16/08/17 15:50:37
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <vector>
#include <algorithm>

#include "List.hpp"

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    static const int LIMIT = 10;

    List<int> intList;
    std::vector<int> intVec;

    std::cout << "Enter " << LIMIT << " integers: ";

    int value = 0;
    for (int i = 0; i < LIMIT; ++i) {
        std::cin >> value;

        intVec.push_back(value);
    }

    // sort the vector then add to list sorted.
    std::sort(intVec.begin(), intVec.end());

    for (int n : intVec) { intList.insertAtBack(n); }

    intList.print();

    intList.printListBackwards();

    return 0;
}  // end method main
