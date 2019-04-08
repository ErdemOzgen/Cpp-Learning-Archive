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

#include <iomanip>
#include <iostream>

int main(int argc, const char *argv[]) {
    int x = 10000;

    // display x
    std::cout << x << " printed as int right and left justified\n"
              << "use as hex weith internal justification.\n"
              << "Using the default pad character (space):" << std::endl;

    // display x with base
    std::cout << std::showbase << std::setw(10) << x << std::endl;

    // display x with left justification
    std::cout << std::left << std::setw(10) << x << std::endl;

    // display x as hex with internal justification
    std::cout << std::internal << std::setw(10) << std::hex << x << std::endl
              << std::endl;

    std::cout << "Using various padding characters:" << std::endl;

    // display x using padded characters (right justification)
    std::cout << std::right;
    std::cout.fill('*');
    std::cout << std::setw(10) << std::dec << x << std::endl;

    // display x using padded characters (left justification)
    std::cout << std::left << std::setw(10) << std::setfill('%') << x
              << std::endl;

    // display x using padded characters (internal justification)
    std::cout << std::internal << std::setw(10) << std::setfill('^') << std::hex
              << x << std::endl;

    return 0;
}
