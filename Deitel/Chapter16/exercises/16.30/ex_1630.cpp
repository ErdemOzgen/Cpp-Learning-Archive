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
#include <stdexcept>

void function() {
    try {
        if (false) {
            throw 9;  // caught in function
        } else {
            throw 10.5;  // caught in main
        }
    } catch (int e) {
        std::cout << "Caught in Function: i: " << e << std::endl;
    }
}

int main(int argc, const char *argv[]) {
    try {
        function();
    } catch (double &e) {
        std::cout << "Caught in main: d: " << e << std::endl;
    } catch (...) {
        std::cout << "test" << std::endl;
    }
    return 0;
}
