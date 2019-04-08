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
    const int arraySize = 11;

    int n[arraySize] = {0, 0, 0, 0, 0, 0, 1, 2, 4, 2, 1};

    std::cout << "Grade distribution: " << std::endl;

    for (int i = 0; i < arraySize; ++i) {
        // output bar labels
        if (i == 0) {
            std::cout << "  0-9: ";
        } else if (i == 10) {
            std::cout << "  100: ";
        } else {
            std::cout << i * 10 << "-" << (i * 10) + 9 << ": ";
        }

        // print bar of asterisks
        for (int stars = 0; stars < n[i]; ++stars) {
            std::cout << '*';
        }

        std::cout << std::endl;
    }
    return 0;
}
