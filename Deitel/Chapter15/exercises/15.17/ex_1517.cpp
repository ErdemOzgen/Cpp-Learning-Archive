/*
 * =====================================================================================
 *
 *       Filename:  ex_1517.cpp
 *
 *    Description:  Exercise 15.17 - Printing a Table of ASCII Values
 *
 *        Version:  1.0
 *        Created:  24/10/16 20:37:51
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iomanip>
#include <iostream>

int main(int argc, const char *argv[]) {
    std::cout << std::setw(5) << "dec" << std::setw(5) << "oct" << std::setw(5)
              << "hex" << std::setw(5) << "char" << std::endl;

    for (int i = 33; i <= 126; ++i) {
        std::cout << std::setw(5) << i << std::setw(5) << std::oct << i
                  << std::setw(5) << std::hex << i << std::setw(5) << std::dec
                  << static_cast<char>(i) << std::endl;
    }
    return 0;
}
