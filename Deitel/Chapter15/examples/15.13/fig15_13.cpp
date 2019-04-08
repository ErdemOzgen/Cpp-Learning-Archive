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
    // display double values with default stream format
    std::cout << "Before using showpoint" << std::endl
              << "9.99000 prints as: " << 9.9900 << std::endl
              << "9.90000 prints as: " << 9.9000 << std::endl
              << "9.00000 prints as: " << 9.0000 << std::endl;

    // display double value after showpoint
    std::cout << std::showpoint << "After using showpoint" << std::endl
              << "9.99000 prints as: " << 9.9900 << std::endl
              << "9.90000 prints as: " << 9.9000 << std::endl
              << "9.00000 prints as: " << 9.0000 << std::endl;

    return 0;
}
