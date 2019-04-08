/*
 * =====================================================================================
 *
 *       Filename:  fig19_04.cpp
 *
 *    Description:  Fig. 19.04 - BinarySearch test program.
 *
 *        Version:  1.0
 *        Created:  06/03/17 17:22:44
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "BinarySearch.hpp"

#include <iostream>

int main(int argc, const char* argv[]) {
    int searchInt;
    int position;

    // create vector and output it
    BinarySearch searchVector(15);
    searchVector.displayElements();

    // get input from user
    std::cout << "\nPlease enter an integer value (-1 to quit): ";
    std::cin >> searchInt;
    std::cout << std::endl;

    // repeatedly input an integer: -1 terminates the program
    while (searchInt != -1) {
        // use binary search to try to find integer
        position = searchVector.binarySearch(searchInt);

        // return value of -1 indicates integer was not found
        if (position == -1)
            std::cout << "The integer " << searchInt << " was not found.\n";
        else
            std::cout << "The integer " << searchInt
                      << " was found in position " << position << ".\n";

        // get input from user
        std::cout << "\n\nPlease enter an integer value (-1 to quit): ";
        std::cin >> searchInt;
        std::cout << std::endl;
    }

    return 0;
}
