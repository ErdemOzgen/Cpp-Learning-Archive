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
    int num1;

    std::cout << "Enter an integer: ";
    std::cin >> num1;

    std::cout << num1 << " is " << ((num1 % 2 == 0) ? "even" : "odd") << std::endl;

    return 0;
}
