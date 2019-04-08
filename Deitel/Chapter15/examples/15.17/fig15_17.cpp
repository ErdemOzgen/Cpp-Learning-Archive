
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
    int x = 100;

    // use showbase to show number base
    std::cout << "Printing integers preceded by their base: " << std::endl
              << std::showbase;

    std::cout << x << std::endl;              // print decimal value
    std::cout << std::oct << x << std::endl;  // print octal value
    std::cout << std::hex << x << std::endl;  // print hexadecimal value

    return 0;
}
