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
    // variable declarations
    int number1;  // first integer to add
    int number2;  // second integer to add
    int sum;      // sum of number1 and number2

    std::cout << "Enter first integer: ";  // prompt user for data //std measns using from namespace std
    //for name space std http://www.cplusplus.com/forum/beginner/61121/
    std::cin >> number1;  // read the first integer from user into number1

    std::cout << "Enter second integer: ";  // prompt user for data
    std::cin >> number2;  // read the second integer from user into number2

    sum = number1 + number2;

    std::cout << "Sum is " << sum << std::endl;

    return 0;
}
