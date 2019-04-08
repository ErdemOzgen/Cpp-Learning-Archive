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
#include "Array.hpp"

#include <iostream>

void outputArray(const Array&);

int main(int argc, const char* argv[]) {
    Array integers1(7);

    outputArray(integers1);
    outputArray(1);  // convert 3 to an Array and output Array's contents
    return 0;
}
// print Array contents
void outputArray(const Array& arrayToOutput) {
    std::cout << "The Array received has " << arrayToOutput.getSize()
              << " elements. The contents are:\n"
              << arrayToOutput << std::endl;
}
