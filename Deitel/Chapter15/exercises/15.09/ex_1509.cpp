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

int main(int argc, const char *argv[]) {
    int i = 12345;
    float f = 1.2345;

    for (int j = 10; j > 1; --j) {
        std::cout << "-----\nWidth: " << j << "\n-----\n"
                  << std::setw(j) << i << "\n"
                  << std::setw(j) << f << std::endl;
    }

    return 0;
}
