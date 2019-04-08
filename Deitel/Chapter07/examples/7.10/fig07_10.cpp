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
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

int main(int argc, const char *argv[]) {
    const int arraySize = 7;

    int frequency[arraySize] = {};

    srand(time(0));

    for (int roll = 1; roll <= 6000000; ++roll) {
        ++frequency[1 + rand() % 6];
    }

    std::cout << "Face" << std::setw(13) << "Frequency" << std::endl;

    for (int face = 1; face < arraySize; ++face) {
        std::cout << std::setw(4) << face << std::setw(13) << frequency[face]
                  << std::endl;
    }
    return 0;
}
