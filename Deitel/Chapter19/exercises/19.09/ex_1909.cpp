/*
 * =====================================================================================
 *
 *       Filename:  ex_1909.cpp
 *
 *    Description:  Exercise 19.09 - Recursive Binary Search
 *
 *        Version:  1.0
 *        Created:  10/03/17 17:12:41
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

int recursiveBinarySearch(const std::vector<int>&, int, int, int);

int getRandomNumber(int, int);

// print a vector
template <typename T>
void print(const std::vector<T>& data) {
    for (T elem : data) { std::cout << elem << " "; }

    std::cout << std::endl;
}

std::random_device rd;
std::mt19937 gen(rd());

int main(int argc, const char* argv[]) {
    const size_t limit = 100;
    const size_t size = 100;
    std::vector<int> intVec;

    int searchKey = (getRandomNumber(1, limit));

    for (size_t i = 0; i < size; ++i) {
        intVec.push_back(getRandomNumber(1, limit));
    }

    std::cout << "Unsorted" << std::endl;
    print(intVec);

    std::sort(intVec.begin(), intVec.end());

    std::cout << "Searching for key " << searchKey << " in sorted vector:\n\n";
    print(intVec);

    int result = recursiveBinarySearch(intVec, searchKey, 0, intVec.size() - 1);

    std::cout << "\n" << searchKey;

    if (result > -1) {
        std::cout << " found at location " << result << std::endl;
    } else {
        std::cout << " not found." << std::endl;
    }
    return 0;
}
// recursive binary search
int recursiveBinarySearch(const std::vector<int>& intVec, int searchKey, int low, int high) {
    int middle = (low + high + 1) / 2;

    if (low > high) { return -1; }

    if (searchKey == intVec[middle]) { return middle; }

    if (searchKey < intVec[middle]) {
        return recursiveBinarySearch(intVec, searchKey, low, (middle - 1));
    } else {
        return recursiveBinarySearch(intVec, searchKey, (middle + 1), high);
    }
}

/**
 * Gets and returns random int.
 * @return int
 */
int getRandomNumber(int low, int high) {
    return std::uniform_int_distribution<int>{low, high}(gen);
}  // end method getRandomNumber
