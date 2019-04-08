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
#include "DateAndTime.hpp"

#include <iostream>

int main(int argc, const char *argv[]) {
    DateAndTime dt(1, 1, 2000, 23, 59, 59);

    std::cout << dt << std::endl;

    for (int i = 0; i < 10000; ++i) {
        dt.tick();

        std::cout << dt << std::endl;
    }
    return 0;
}
