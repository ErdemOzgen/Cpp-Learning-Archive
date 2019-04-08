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
#include "Integer.hpp"

#include <iostream>
#include <memory>

int main(int argc, const char *argv[]) {
    std::cout << "Creating a unique_ptr object that points to an Integer\n";

    // "aim" unique_ptr at Integer object
    std::unique_ptr<Integer> ptrToInteger(new Integer(7));

    std::cout << "\nUsing the unique_ptr to manipulate the Integer\n";
    ptrToInteger->setInteger(99);

    // use unique_ptr to get Integer value
    std::cout << "Integer after setInteger: " << (*ptrToInteger).getInteger()
              << "\n\n";

    return 0;
}
