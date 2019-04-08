/*
 * =====================================================================================
 *
 *       Filename:  ex_2008.cpp
 *
 *    Description:  Exercise 20.08 - Summing Average Elements in a List
 *
 *        Version:  1.0
 *        Created:  12/06/17 18:28:27
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

#include "List.hpp"

int main(int argc, const char* argv[]) {
    List<int> intList;
    std::vector<int> data;  // for sorting the data

    const int RAND_LIMIT = 100;
    const int LIST_SIZE = 25;

    std::random_device rd;
    std::mt19937 gen(rd());

    // generate the random numbers
    for (int i = 0; i < LIST_SIZE; ++i) {
        data.push_back(std::uniform_int_distribution<int>{0, RAND_LIMIT}(gen));
    }

    // sort the data
    std::sort(data.begin(), data.end());

    // build the list
    for (unsigned int i = 0; i < data.size(); ++i) {
        intList.insertAtBack(data[i]);
    }

    // calculate sum of elements
    long sum = 0;

     auto iter = intList.begin();

     while (iter != intList.end()) {
         sum += iter->getData();
         iter = iter->next();
     }

    std::cout << "sum: " << sum << " average: " << (sum / LIST_SIZE) << std::endl;

    intList.print();
    std::cout << std::endl;

    return 0;
}
