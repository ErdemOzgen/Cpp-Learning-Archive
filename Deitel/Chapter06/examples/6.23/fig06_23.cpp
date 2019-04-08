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

int number = 7;  // global variable named number

int main(int argc, const char *argv[]) {
    double number = 10.0f;  // local variable named number

    std::cout << "Local double value of number = " << number
              << "\nGlobal int value of number = " << ::number << std::endl;
    return 0;
}
