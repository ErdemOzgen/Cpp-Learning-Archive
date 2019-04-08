/*
 * =============================================================================
 *
 *       Filename:  ex_2106.cpp
 *
 *    Description:  Exercise 21.06 - Shifting and Printing an Integer.
 *
 *        Version:  1.0
 *        Created:  27/02/18 12:32:25
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =============================================================================
 */
#include <iostream>
#include <bitset>

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    int i = 16;

    std::cout << "i = " << std::bitset<8>(i) << "\ni >> 4 = ";
    i = i >> 4;
    std::cout << std::bitset<8>(i) << std::endl;

    return 0;
}  // end method main
