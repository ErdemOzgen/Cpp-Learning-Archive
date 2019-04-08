/*
 * =====================================================================================
 *
 *       Filename:  fig08_06.cpp
 *
 *    Description:  Fig. 8.6: Pass-by-value used to cube a variable's value
 *
 *        Version:  1.0
 *        Created:  29/04/16 16:31:04
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>

int cubeByValue(int);

int main(int argc, const char *argv[]) {
    int number = 5;

    std::cout << "The original value of number is " << number;

    number = cubeByValue(number);

    std::cout << "\nThe new value of number is " << number << std::endl;
    return 0;
}
// calculate and return cube of integer argument
int cubeByValue(int n) { return n * n * n; }
