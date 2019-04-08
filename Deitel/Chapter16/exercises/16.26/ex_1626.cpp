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

int main(int argc, const char *argv[]) {
    // uncomment to see that it Pokèmon's them all
    try {
        // throw std::exception();
        // throw std::invalid_argument("invalid argument");;
        throw std::out_of_range("out of range");
    } catch (...) {
        std::cout << "Exception Caught" << std::endl;
    }
    return 0;
}
