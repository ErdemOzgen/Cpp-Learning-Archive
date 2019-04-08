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
#include "Interface.hpp"

#include <iostream>

int main(int argc, const char *argv[]) {
    Interface i(5);

    std::cout << "Interface contains " << i.getValue() << " before setValue"
              << std::endl;

    i.setValue(10);

    std::cout << "Interface contains " << i.getValue() << " after setValue"
              << std::endl;
    return 0;
}
