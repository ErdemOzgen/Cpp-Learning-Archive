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

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    int count = 1;
    bool exit = false;

    while (!exit) {
        std::cout << count++ << " ";

        exit = (count == 5);
    }

    std::cout << "\nBroke out of loop at count = " << count << std::endl;

    return 0;
}  // end method main
