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

int reverseDigits(int);

int main(int argc, const char *argv[]) {
    int n;
    std::cout << "Program to reverse the digits of a given int\n" << std::endl;

    std::cout << "Enter a number to be reversed: ";
    std::cin >> n;

    std::cout << "\n" << reverseDigits(n) << std::endl;
    return 0;
}
// returns a reversed integer
int reverseDigits(int n) {
    int tmp = 0;
    int digits = 1;

    // get number of digits
    for (int d = 1; d <= n; d *= 10) {
        digits *= 10;
    }

    while (n != 0) {
        // reduce digits before using (avoid multiplying final value)
        digits /= 10;
        tmp += n % 10 * digits;

        n /= 10;
    }
    return tmp;
}
