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
    const int arraySize = 10;

    int s[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        s[i] = 2 + 2 * i;
    }

    std::cout << "Element" << std::setw(13) << "Value" << std::endl;

    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::setw(7) << i << std::setw(13) << s[i] << std::endl;
    }
    return 0;
}
