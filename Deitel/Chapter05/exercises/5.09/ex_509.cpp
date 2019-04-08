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
    int product = 1;

    std::cout << "Product of odd integers 1 to 15: ";

    for (int i = 1; i <= 15; i += 2) {
        product *= i;
    }

    std::cout << product << std::endl;

    return 0;
}
