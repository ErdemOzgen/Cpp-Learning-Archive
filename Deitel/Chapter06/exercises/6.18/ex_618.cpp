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

int integerPower(int, int);

int main(int argc, const char *argv[]) {
    int base, exponent;

    std::cout << "Enter base and exponent: ";
    std::cin >> base >> exponent;

    std::cout << base << " to the power of " << exponent << ": "
              << integerPower(base, exponent) << std::endl;

    return 0;
}
// returns base to the power of exponent
int integerPower(int base, int exponent) {
    // base case
    if (exponent <= 0) {
        return 1;
    }

    return base * integerPower(base, exponent - 1);
}
