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

#include "Time.hpp"

int main(int argc, const char *argv[]) {
    Time time1;
    Time time2(12, 12, 12);

    std::cout << "time1: ";
    time1.printUniversal();
    std::cout << std::endl;
    time1.printStandard();

    std::cout << "\n\ntime2: ";
    time2.printUniversal();
    std::cout << std::endl;
    time2.printStandard();
    std::cout << std::endl;

    return 0;
}
