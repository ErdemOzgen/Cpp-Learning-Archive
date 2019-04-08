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
#include <iomanip>
#include <iostream>

int main(int argc, const char *argv[]) {
    for (int counter = 1; counter <= 20; ++counter) {
        std::cout << std::setw(10) << (1 + rand() % 6);

        // if counter divisible by 5, start a new line of output
        if (counter % 5 == 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}
