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

int gcd(int, int);

int main(int argc, const char *argv[]) {
    int num1, num2;

    std::cout << "Program to print the gcd of two integers\n" << std::endl;

    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;

    std::cout << "Greatest Common Divisor: " << gcd(num1, num2) << std::endl;
    return 0;
}
// find and return the greatest common divisor of two integers
int gcd(int x, int y) {
    // smaller number subtracted from larger
    // difference stored in place of larger
    // repeat until 2 numbers equal > gcd

    while (x != y) {
        if (x > y) {
            x -= y;
        } else {
            y -= x;
        }
    }
    // can return either x or y as both will be the same
    return x;
}
