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
#include <string>

int main(int argc, const char* argv[]) {
    std::string row = "* * * * * * * *";

    std::cout << "Eight Output Statements:\n" << std::endl;

    std::cout << row << std::endl;
    std::cout << ' ' << row << std::endl;
    std::cout << row << std::endl;
    std::cout << ' ' << row << std::endl;
    std::cout << row << std::endl;
    std::cout << ' ' << row << std::endl;
    std::cout << row << std::endl;
    std::cout << ' ' << row << std::endl;

    std::cout << "\nFor Loop:\n" << std::endl;
    for (int i = 0; i < 8; ++i) {
        if (i % 2 != 0) {
            std::cout << ' ';
        }

        std::cout << row << std::endl;
    }

    return 0;
}
