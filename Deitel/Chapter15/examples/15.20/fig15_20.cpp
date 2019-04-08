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

int main(int argc, const char *argv[]) {
    bool booleanValue = true;

    // display default true booleanValue
    std::cout << "booleanValue is " << booleanValue << std::endl;

    // display booleanValue after using boolalpha
    std::cout << "booleanValue (after using boolalpha) is " << std::boolalpha
              << booleanValue << std::endl
              << std::endl;

    std::cout << "switch booleanValue and use noboolalpha" << std::endl;
    booleanValue = false;
    std::cout << std::noboolalpha << std::endl;

    // display default false booleanValue after using noboolalpha
    std::cout << "booleanValue is " << booleanValue << std::endl;

    // display booleanValue after using boolalpha again
    std::cout << "booleanValue (after using boolalpha) is " << std::boolalpha
              << booleanValue << std::endl;

    return 0;
}
