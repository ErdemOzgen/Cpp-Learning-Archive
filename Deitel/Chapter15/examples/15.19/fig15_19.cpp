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

int main(int argc, const char *argv[]) {
    std::cout << "Printing uppercase letters in scientific" << std::endl
              << "notation exponents and hexadecimal values:" << std::endl;

    // use std::uppercase to display uppercase letters; use std::hex and
    // std::showbase to display hexadecimal value and its base
    std::cout << std::uppercase << 4.345e10 << std::endl
              << std::hex << std::showbase << 123456789 << std::endl;

    return 0;
}
