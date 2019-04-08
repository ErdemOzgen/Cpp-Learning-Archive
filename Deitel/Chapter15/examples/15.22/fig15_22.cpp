
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
    int integerValue;

    // display results of cin functions
    std::cout << "Before a bad input operation:"
              << "\ncin.rdstate(): " << std::cin.rdstate()
              << "\n    cin.eof(): " << std::cin.eof()
              << "\n   cin.fail(): " << std::cin.fail()
              << "\n    cin.bad(): " << std::cin.bad()
              << "\n   cin.good(): " << std::cin.good()
              << "\n\nExpects an integer, but enter a character: ";

    std::cin >> integerValue;
    std::cout << std::endl;

    // display results of cin functions after bad input
    std::cout << "After a bad input operation:"
              << "\ncin.rdstate(): " << std::cin.rdstate()
              << "\n    cin.eof(): " << std::cin.eof()
              << "\n   cin.fail(): " << std::cin.fail()
              << "\n    cin.bad(): " << std::cin.bad()
              << "\n   cin.good(): " << std::cin.good() << std::endl
              << std::endl;

    std::cin.clear();

    // display results of cin function after clearing cin
    std::cout << "After cin.clear()"
              << "\ncin.fail(): " << std::cin.fail()
              << "\ncin.good(): " << std::cin.good() << std::endl;

    return 0;
}
