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
#include <exception>

int main(int argc, const char *argv[]) {
    try {
        try {
            throw std::exception();
        } catch (std::exception) {
            std::cout << "Original throw caught" << std::endl;
            throw;
        }
    } catch (std::exception) {
        std::cout << "Rethrow caught" << std::endl;
    }

    return 0;
}
