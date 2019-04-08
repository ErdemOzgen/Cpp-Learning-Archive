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
    // i = rows, j = diamonds, k = spaces
    for (int i = 1, j = 1, k = 4; i <= 9; i++) {
        for (int s = 0; s < k; s++) {
            std::cout << " ";
        }
        for (int d = 0; d < j; d++) {
            std::cout << "*";
        }

        (i >= 5) ? j -= 2 : j += 2;
        (i >= 5) ? k++ : k--;

        std::cout << std::endl;
    }
    return 0;
}
