/*
 * =====================================================================================
 *
 *       Filename:  ex_2007.cpp
 *
 *    Description:  Exercise 20.07 - Merging Ordered Lists
 *
 *        Version:  1.0
 *        Created:  12/06/17 17:08:03
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

#include "List.hpp"

int main(int argc, const char* argv[]) {
    List<int> intList1;
    List<int> intList2;

    const int ARR_SIZE = 10;

    int data1[ARR_SIZE] = {1, 3, 5, 7, 8, 10, 12, 15, 17, 20};
    int data2[ARR_SIZE] = {2, 4, 6, 9, 11, 13, 14, 16, 18, 19};

    for (int i = 0; i < ARR_SIZE; ++i) {
        intList1.insertAtBack(data1[i]);
        intList2.insertAtBack(data2[i]);
    }

    std::cout << "Before Merge\nintList1 : ";
    intList1.print();
    std::cout << "\nintList2 : ";
    intList2.print();
    std::cout << std::endl;

    std::cout << "After Merge:\n";
    List<int> mergeList = intList1.merge(intList2);

    mergeList.print();

    std::cout << std::endl;

    return 0;
}
