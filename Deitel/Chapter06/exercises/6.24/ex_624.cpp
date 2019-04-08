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

void separateInt(long);

int main(int argc, const char *argv[]) {
    long n;

    std::cout << "A program to print a separated a sequence of integers\n"
              << std::endl;

    std::cout << "Enter multi digit integer: ";
    std::cin >> n;

    separateInt(n);

    return 0;
}
// prints n as a space separated integer
void separateInt(long n) {
    long numDigits = 1;  // number of tens places

    // get number of digits
    for (long i = n; i > 10; i /= 10) {
        numDigits *= 10;
    }

    while (numDigits > 0) {
        // print remainder for individual digit in right order
        std::cout << (n / numDigits) % 10 << " ";

        numDigits /= 10;
    }
    std::cout << std::endl;
}
