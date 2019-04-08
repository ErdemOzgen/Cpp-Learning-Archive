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
    int count = 0;

    std::cout << "Program to print a square of asterisks\n" << std::endl;

    while (true) {
        std::cout << "Enter a number between 1 and 20: ";
        std::cin >> count;

        if (count > 0 && count <= 20) {
            break;
        }
    }

    for (int i = 0; i < count; i++) {
        if (count > 1) {
            printf("*");
        }

        for (int j = 1; j < count - 1; j++) {
            if (i == 0 || i == count - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("*\n");
    }
    return 0;
}
