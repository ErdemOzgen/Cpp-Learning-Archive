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
    std::cout << std::right << std::setw(12) << "Farenheit" << std::setw(12)
              << "Celsuis" << std::endl;

    for (int i = 0; i <= 212; ++i) {
        std::cout << std::right << std::setw(12) << i << std::right
                  << std::setw(12) << std::setprecision(3) << std::showpos
                  << std::fixed << ((5.0 / 9.0) * (i - 32)) << std::endl;
    }

    return 0;
}
