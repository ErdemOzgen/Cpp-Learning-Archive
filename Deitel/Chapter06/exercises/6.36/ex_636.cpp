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

int power(int, int);

int main(int argc, const char *argv[]) {
    int base, exponent;

    std::cout << "A program to recursively calculate exponents" << std::endl;

    std::cout << "\nEnter the base and exponent: ";
    std::cin >> base >> exponent;

    printf("%d to the power of %d: %d\n", base, exponent, power(base, exponent));

    return 0;
}
// recusively calculate exponents
int power(int base, int exponent) {
    if (exponent == 0) { return 1; }

    return base * power(base, exponent - 1);
}
