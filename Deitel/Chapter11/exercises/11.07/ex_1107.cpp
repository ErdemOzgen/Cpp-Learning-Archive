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

#include "DoubleScriptedArray.hpp"

int main(int argc, const char *argv[]) {
    DoubleScriptedArray intArray(10, 2);

    intArray(1, 1) = 3;

    std::cout << "intArray\n" << intArray;

    std::cout << "intArray(1,1): " << intArray(1, 1) << std::endl;

    DoubleScriptedArray intArray2 = intArray;

    intArray2(0, 5) = 15;
    intArray2(1, 9) = 7;
    std::cout << "intArray2\n" << intArray2;

    return 0;
}
