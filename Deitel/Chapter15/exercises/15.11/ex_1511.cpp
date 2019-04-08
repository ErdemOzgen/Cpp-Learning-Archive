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
#include <string>

int main(int argc, const char *argv[]) {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    int i;
    for (i = 0; input[i] != '\0'; ++i) {}

    std::cout << "Length of string: " << input << " = " << i << std::endl;

    return 0;
}
