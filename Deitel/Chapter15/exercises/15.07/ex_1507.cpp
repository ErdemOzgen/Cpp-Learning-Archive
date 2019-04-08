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
    int intDec, intOct, intHex = 0;

    std::cout << "Enter 3 ints in decimal, octal and hexadecimal formats: ";
    std::cin >> intDec >> intOct >> intHex;

    std::cout << std::left << std::setw(6) << "dec" << std::setw(6) << "oct"
              << std::setw(3) << "hex\n";

    std::cout << std::setw(6) << std::dec << intDec << std::setw(6) << std::oct
              << intDec << std::setw(6) << std::hex << intDec << "\n";

    std::cout << std::setw(6) << std::dec << intOct << std::setw(6) << std::oct
              << intOct << std::setw(6) << std::hex << intOct << "\n";

    std::cout << std::setw(6) << std::dec << intHex << std::setw(6) << std::oct
              << intHex << std::setw(6) << std::hex << intHex << "\n";

    return 0;
}
