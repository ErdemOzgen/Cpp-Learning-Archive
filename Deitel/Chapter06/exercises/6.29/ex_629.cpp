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
#include <math.h>
#include <iostream>

bool isPrime(int);

int main(int argc, const char *argv[]) {
    std::cout << "A program to print all prime numbers between 2 and 10k\n"
              << std::endl;

    for (int i = 2; i < 100; i++) {
        if (isPrime(i)) { std::cout << i << " "; }
    }
    std::cout << std::endl;

    return 0;
}
// determine whether n is prime
bool isPrime(int n) {
    if (n == 1 || n == 2) { return true; }

    // prime numbers cannot be even
    if (n % 2 == 0) { return false; }

    // upper limit sqrt as primes cannot be squared
    for (int i = 2; i < sqrt(n); ++i) {
        // has divisor not prime
        if (n % i == 0) { return false; }
    }
    return true;
}
