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
    int toggle = 0;
    int limit = 1000;

    double pi = 4.0f;
    double divisor = 3.0f;

    std::cout << "Term" << std::setw(4) << "\tPI Approx" << std::endl;

    for (int i = 1; i <= limit; i++) {
        if (toggle == 0) {
            pi -= (4.0f / divisor);
        } else {
            pi += (4.0f / divisor);
        }
        // bit toggle for + - switching above
        toggle = (1 - toggle);

        divisor += 2;

        std::cout << i << std::setw(4) << "\t" << pi << std::endl;
    }
    return 0;
}
