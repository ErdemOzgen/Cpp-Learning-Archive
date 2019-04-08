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
        throw std::exception();
    } catch (std::exception &e) {
        std::cout << "Executed as first: " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Executed IF first" << e.what() << std::endl;
    }

    return 0;
}
