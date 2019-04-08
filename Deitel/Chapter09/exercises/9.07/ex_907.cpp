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

#include "Time.hpp"

int main(int argc, const char *argv[]) {
    Time t1(23, 59, 58);

    std::cout << "t1: ";

    t1.printUniversal();

    std::cout << std::endl;

    for (int i = 0; i < 100; ++i) {
        t1.tick();

        if (i % 10 == 0) {
            t1.printUniversal();

            std::cout << " ";

            t1.printStandard();

            std::cout << std::endl;
        }
    }
    return 0;
}
