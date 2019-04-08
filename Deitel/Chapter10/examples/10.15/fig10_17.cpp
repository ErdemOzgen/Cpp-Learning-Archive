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
#include "Time.hpp"

#include <iostream>

int main(int argc, const char *argv[]) {
    Time t;

    // cascaded function calls
    t.setHour(18).setMinute(30).setSecond(22);

    // output time in universal and standard formats
    std::cout << "Universal time: ";
    t.printUniversal();

    std::cout << "\nStandard time: ";
    t.printStandard();

    std::cout << "\n\nNew standard time: ";

    // cascaded function calls
    t.setTime(20, 20, 20).printStandard();

    std::cout << std::endl;

    return 0;
}
