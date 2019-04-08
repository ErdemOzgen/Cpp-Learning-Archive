/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#include <iostream>
#include <random>

void selectionSort(int[], int);

static const int LIMIT = 10;

int main(int argc, const char *argv[]) {
    int n[LIMIT];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    for (int i = 0; i < LIMIT; ++i) {
        n[i] = dis(gen);
    }

    // print unsorted array
    std::cout << "Before selectionSort: " << std::endl;

    for (int i = 0; i < LIMIT; ++i) {
        std::cout << n[i] << std::endl;
    }

    selectionSort(n, LIMIT);

    // print sorted array
    std::cout << "\nAfter selectionSort: " << std::endl;

    for (int i = 0; i < LIMIT; ++i) {
        std::cout << n[i] << std::endl;
    }

    return 0;
}
// selection sort recursive algorithm
void selectionSort(int n[], int LIMIT) {
    static int startIndex = 0;
    int minIndex = startIndex;

    // exit condition
    if (startIndex >= LIMIT - 1) { return; }

    // get the index of the smallest value
    for (int i = startIndex + 1; i < LIMIT; ++i) {
        if (n[i] < n[minIndex]) { minIndex = i; }
    }

    // swap with n[startIndex]
    int tmp = n[startIndex];
    n[startIndex] = n[minIndex];
    n[minIndex] = tmp;

    // increment startIndex
    ++startIndex;

    selectionSort(n, LIMIT);
}
