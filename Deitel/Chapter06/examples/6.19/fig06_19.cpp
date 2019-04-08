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

int squareByValue(int);
void squareByReference(int &);

int main(int argc, const char *argv[]) {
    int x = 2;
    int z = 4;

    // demonstrate squareByValue
    std::cout << "x = " << x << " before squareByValue\n";
    std::cout << "Value returned by squareByValue: " << squareByValue(x)
              << std::endl;
    std::cout << "x = " << x << " after squareByValue\n" << std::endl;

    // demonstrate squareByReference
    std::cout << "z = " << z << " before squareByReference\n";
    squareByReference(z);
    std::cout << "z = " << z << " after squareByReference\n";

    return 0;
}
// squareByValue multiplies number by itself, stores the result in number and
// returns the new value of number
int squareByValue(int number) { return number *= number; }
// squareByReference multiplies numberRef by itself and stores the result in the
// variable to which numberRef refers in the main function
void squareByReference(int &numberRef) { numberRef *= numberRef; }
