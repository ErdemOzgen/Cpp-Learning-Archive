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

int fibonacci(int);

int main(int argc, const char *argv[]) {
    int n;

    std::cout << "Program to non recursively calculate fibonacci to n\n" << std::endl;

    std::cout << "Enter n: ";
    std::cin >> n;

    printf("Fibonacci to the %dth power: %d\n", n, fibonacci(n));

    return 0;
}
// iteratively calculate fibonacci to n
int fibonacci(int n) {
    int fib = 0;
    int firstTerm = 0;
    int secondTerm = 1;

    for (int i = 0; i < n; ++i) {
        // first two terms are 0 and 1
        if (i <= 1) {
            fib = i;
        } else {
            fib = firstTerm + secondTerm;

            firstTerm = secondTerm;
            secondTerm = fib;
        }
    }

    return fib;
}
