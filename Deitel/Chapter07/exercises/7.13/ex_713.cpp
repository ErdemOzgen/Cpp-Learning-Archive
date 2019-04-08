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
#include <iomanip>
#include <iostream>

int main(int argc, const char *argv[]) {
    // Initialise the 10 elements of integer array counts to zero
    int counts[10] = {};

    // Add 1 to each of the 15 elements of integer array bonus
    int bonus[15] = {};

    for (int i = 0; i < 15; ++i) {
        ++bonus[i];
    }

    // Read 12 values for double array monthlyTemperatures from the keyboard
    double monthlyTemperature[12] = {};

    for (int i = 0; i < 12; ++i) {
        std::cout << "(" << i + 1 << "/12) Enter temperature: ";
        std::cin >> monthlyTemperature[i];
    }

    // print the 5 values of integer array bestScore in column format
    int bestScore[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i) {
        std::cout << bestScore[i] << std::setw(5);
    }

    std::cout << std::endl;
    return 0;
}
