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

void printArray(int[], int);
void swap(int*, int*);

const int limit = 10;

int main(int argc, const char *argv[]) {
    std::cout << "A program that uses bubble sort to sort an integer array"
              << std::endl;

    srand(time(0));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);

    int n[limit] = {};

    // randomise elements of n
    for (int i = 0; i < limit; ++i) {
        n[i] = dis(gen);
    }

    std::cout << "Unsorted array n: " << std::endl;
    printArray(n, limit);

    // BUBBLE SORT
    for (int i = 0; i < limit - 1; ++i) {
        for (int j = 0; j < limit - 1; ++j) {
            if (n[j] > n[j + 1]) {
                swap(&n[j], &n[j + 1]);
            }
        }
    }

    std::cout << "\nSorted array n: " << std::endl;
    printArray(n, limit);

    return 0;
}

/**
 * Prints the given array
 * @param int[]
 * @param int
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << std::endl;
    }
}  // end method print

/**
 * Swaps the given elements
 * @param int*
 * @param int*
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}  // end method swap
