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

int main(int argc, const char *argv[]) {
    double num = 0.0f;

    std::cout << "Program to round number to the nearest integer" << std::endl;

    while (num != -1) {
        std::cout << "Enter a number to round (-1 to exit): ";
        std::cin >> num;

        if (num == -1) {
            break;
        }

        std::cout << "num: " << num << "\nrounded: " << floor(num + .5)
                  << std::endl;
    }

    return 0;
}
