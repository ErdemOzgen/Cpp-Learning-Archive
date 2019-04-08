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

inline int MAX(int a, int b) { return (a > b ? a : b); }

int main(int argc, const char *argv[]) {
    int counter = 0;
    int number = 0;
    int fLargest = 0;
    int sLargest = 0;

    std::cout << "Program to find the largest of 10 numbers\n" << std::endl;

    while (counter < 10) {
        std::cout << "Enter number: (" << (10 - counter) << " remaining): ";
        std::cin >> number;

        if (MAX(fLargest, number) == number) {
            sLargest = fLargest;
            fLargest = number;
        }

        ++counter;
    }

    std::cout << "First Largest: " << fLargest
              << "\nSecond Largest: " << sLargest << std::endl;

    return 0;
}
