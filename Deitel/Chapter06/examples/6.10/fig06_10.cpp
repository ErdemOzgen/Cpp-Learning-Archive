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
    unsigned seed;

    std::cout << "Enter seed: ";
    std::cin >> seed;

    srand(seed);

    for (int counter = 0; counter <= 10; ++counter) {
        std::cout << std::setw(10) << (1 + rand() % 6);

        if (counter % 5 == 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}
