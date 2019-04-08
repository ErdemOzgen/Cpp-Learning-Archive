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

inline bool isEven(int x) { return (x % 2 == 0); }

int main(int argc, const char *argv[]) {
    int input = 0;

    std::cout << "Program to determine whether an integer is even\n"
              << std::endl;

    while (input >= 0) {
        std::cout << "Enter an integer (-1 to quit): ";
        std::cin >> input;

        if (input >= 0) {
            std::cout << input << ":" << (isEven(input) ? "" : " not")
                      << " even" << std::endl;
        }
    }
    return 0;
}
