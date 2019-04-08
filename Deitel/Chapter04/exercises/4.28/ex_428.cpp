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
    for (int i = 1; i <= 8; i++) {
        if (i % 2 == 0) {
            std::cout << ' ';
        }
        for (int j = 0; j < 8; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    return 0;
}
