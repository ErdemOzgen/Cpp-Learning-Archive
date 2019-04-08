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

#include "Date.hpp"

int main(int argc, const char *argv[]) {
    Date d1(11, 30, 2015);

    for (int i = 0; i < 365; ++i) {
        d1.nextDay();

        std::cout << d1 << std::endl;
    }
    return 0;
}
