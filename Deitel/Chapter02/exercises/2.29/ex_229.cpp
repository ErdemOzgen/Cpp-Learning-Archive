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
    std::cout << "integer square  cube" << std::endl;

    for (int i = 0; i <= 10; ++i) {
        std::cout << i << "\t" << (i * i) << "\t" << (i * i * i) << std::endl;
    }

    return 0;
}
