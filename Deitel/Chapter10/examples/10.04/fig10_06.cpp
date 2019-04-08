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
#include "Increment.hpp"

#include <iostream>

int main(int argc, const char *argv[]) {
    Increment value(10, 5);

    std::cout << "Before incrementing: ";
    value.print();

    for (int j = 1; j <= 3; ++j) {
        value.addIncrement();

        std::cout << "After increment " << j << ": ";
        value.print();
    }
    return 0;
}
