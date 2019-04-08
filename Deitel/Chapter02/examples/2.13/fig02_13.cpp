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

int main(int argc, const char *argv[]) {
    int number1;
    int number2;

    std::cout << "Enter two integers to compare: ";  // prompt user for data
    std::cin >> number1 >> number2;  // read two integers from user

    if (number1 == number2)
        std::cout << number1 << " == " << number2 << std::endl;

    if (number1 != number2)
        std::cout << number1 << " != " << number2 << std::endl;

    if (number1 < number2)
        std::cout << number1 << " < " << number2 << std::endl;

    if (number1 > number2)
        std::cout << number1 << " > " << number2 << std::endl;

    if (number1 <= number2)
        std::cout << number1 << " <= " << number2 << std::endl;

    if (number1 >= number2)
        std::cout << number1 << " >= " << number2 << std::endl;

    return 0;
}
