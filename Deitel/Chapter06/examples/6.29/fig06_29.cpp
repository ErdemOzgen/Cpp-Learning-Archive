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

unsigned long factorial(unsigned long);

int main(int argc, const char *argv[]) {
    // calculate factorials of 0 through 10
    for (int counter = 0; counter <= 10; ++counter) {
        std::cout << std::setw(2) << counter << "! = " << factorial(counter)
                  << std::endl;
    }
    return 0;
}
// recursive definition of function factorial
unsigned long factorial(unsigned long number) {
    // base case
    if (number <= 1) {
        return 1;
    } else {
        return number * factorial(number - 1);
    }
}
