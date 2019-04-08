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
    char c = 'X';
    char *cp = &c;

    std::cout << static_cast<int>(*cp) << "\n"
              << static_cast<unsigned int>(*cp) << "\n"
              << static_cast<short int>(*cp) << "\n"
              << static_cast<unsigned short int>(*cp) << "\n"
              << static_cast<signed short int>(*cp) << "\n"
              << static_cast<long int>(*cp) << "\n"
              << static_cast<signed long int>(*cp) << "\n"
              << static_cast<unsigned long int>(*cp) << std::endl;

    return 0;
}
