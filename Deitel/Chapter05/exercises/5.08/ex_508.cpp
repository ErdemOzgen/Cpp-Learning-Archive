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
    int counter = 0;
    int smallest = 0;
    int current = 0;

    std::cout
        << "Enter a list of space separated integers to determine the smallest"
        << "first entry is number of separate entries\n> ";
    std::cin >> counter;

    // set current smallest
    smallest = 0;

    for (int i = 0; i < counter; i++) {
        std::cin >> current;

        if ((current < smallest) || (i == 0)) {
            smallest = current;
        }
    }

    std::cout << "Smallest: " << smallest << std::endl;
    return 0;
}
