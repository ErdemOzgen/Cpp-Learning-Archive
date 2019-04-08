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
    double d = 100.453627;

    std::cout << std::left << std::setw(8) << "10" << std::setw(12) << "100"
              << std::setw(12) << "1000" << std::setw(12) << "10000"
              << std::endl;

    std::cout << std::setw(8) << std::fixed << std::setprecision(1) << d
              << std::setw(12) << std::fixed << std::setprecision(2) << d
              << std::setw(12) << std::fixed << std::setprecision(3) << d
              << std::setw(10) << std::fixed << std::setprecision(4) << d
              << std::endl;
    return 0;
}
