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
    int integerValue = 1000;
    double doubleValue = 0.0947628;

    // display flags value, int and double values (original format)
    std::cout << "The value of the flags variable is: " << std::cout.flags()
              << "\nPrint int and double in original format:\n"
              << integerValue << '\t' << doubleValue << std::endl
              << std::endl;

    // use cout flags function to save original format
    std::ios_base::fmtflags originalFormat = std::cout.flags();
    std::cout << std::showbase << std::oct << std::scientific;  // change format

    // display flags value, int and double values (new format)
    std::cout << "The value of the flags variable is: " << std::cout.flags()
              << "\nPrint int and double in original format:\n"
              << integerValue << '\t' << doubleValue << std::endl
              << std::endl;

    std::cout.flags(originalFormat);  // restore format

    // display the flags value, int and double values (original format)
    std::cout << "The value of the flags variable is: " << std::cout.flags()
              << "\nPrint int and double in original format:\n"
              << integerValue << '\t' << doubleValue << std::endl
              << std::endl;

    return 0;
}
