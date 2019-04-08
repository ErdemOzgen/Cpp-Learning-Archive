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
#include <stdio.h>
#include <iostream>

int factorialA(int);
int factorialB(int);
int factorialC(int);

int main(int argc, const char *argv[]) {
    int a, b, c = 0;

    std::cout
        << "A program to determine the factorial of a non-negative integer"
        << std::endl;

    std::cout << "Enter a non-negative integer: ";
    std::cin >> a;

    std::cout << "Enter the desired accuracy of e: ";
    std::cin >> b;

    std::cout << "Enter the desired accuracy of e: ";
    std::cin >> c;

    printf("Factorial A: %d\nFactorial B: %d\nFactorial C: %d\n", factorialA(a), factorialB(b), factorialC(c));
    return 0;
}
// A - compute and return factorial
// n! = n * (n-1) * (n-2) * (n-3) * ... * 1
int factorialA(int n) {
    int factorial = 1;

    for (int i = 1; i <= n; i++) {
        factorial *= n;
    }

    return factorial;
}
// B - compute mathematical constant e
// e = 1 + 1/1! + 1/2! + 1/3! + ...
int factorialB(int e) { return e; }
// C - compute mathematical constant of e^x
// e^x = 1 + x/1! + x^2/2! + x^3/3! + ...
int factorialC(int e) { return e; }
