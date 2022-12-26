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
#include <string>
static int i=0;
void printDigits(int);//function prototype  https://codescracker.com/cpp/cpp-function-definition.htm
/**
 * A function prototype is a declaration in C and C++ of a function,
 * its name, parameters and return type before its actual declaration. 
 * This enables the compiler to perform more robust type checking
*/
int main(int argc, const char *argv[]) {
    int num;
     
    std::cout << "Enter a five digit integer: ";
    std::cin >> num;

    printDigits(num);

    std::cout << std::endl;

    return 0;
}

/**
 * Seperates and prints digits in the correct order.
 * Prints in correct order using stack unwinding.
 * @param num.
 */
void printDigits(int num) {
    const std::string SPACES = "   ";
    if (num / 10 > 0) {
        printDigits(num / 10);
    }
    i++;
    std::cout << num % 10 << SPACES;
    //std::cout<<i<<SPACES;
}
