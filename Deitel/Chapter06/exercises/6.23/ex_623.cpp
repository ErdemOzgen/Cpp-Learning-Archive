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

void squareOfChars(int, char);

int main(int argc, const char *argv[]) {
    int n;
    char fillChar;

    std::cout << "Program to print a square of size n of any character\n"
              << std::endl;

    std::cout << "Enter side: ";
    std::cin >> n;

    std::cout << "Enter char: ";
    std::cin >> fillChar;

    squareOfChars(n, fillChar);

    return 0;
}
// prints a square of fillChar of size n
void squareOfChars(int n, char fillChar) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << fillChar;
        }
        std::cout << std::endl;
    }
}
