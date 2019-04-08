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

unsigned long fibonacci(unsigned long);

int main(int argc, const char *argv[]) {
    // calculate fibonacci values of 0 through 10
    for (int counter = 0; counter <= 10; ++counter) {
        std::cout << "fibonacci(" << counter << ") = " << fibonacci(counter)
                  << std::endl;
    }

    // display higher fibonacci values
    std::cout << "fibonacci(20) = " << fibonacci(20) << std::endl;
    std::cout << "fibonacci(30) = " << fibonacci(30) << std::endl;
    std::cout << "fibonacci(35) = " << fibonacci(35) << std::endl;

    return 0;
}
// recursive function fibonacci
unsigned long fibonacci(unsigned long number) {
    // base cases
    if ((number == 0) || (number == 1)) {
        return number;
    } else {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}
