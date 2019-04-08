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
#include "Date.hpp"

#include <iostream>

int main(int argc, const char *argv[]) {
    Date d1(12, 27, 2010);
    Date d2;

    std::cout << "d1 is " << d1 << "\nd2 is " << d2;
    std::cout << "\n\nd1 += 7 is " << (d1 += 7);

    d2.setDate(2, 28, 2008);
    std::cout << "\n\n  d2 is " << d2;
    std::cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";

    Date d3(7, 13, 2010);

    std::cout << "\n\nTesting the prefix increment operator:\n"
              << "  d3 is " << d3 << std::endl;
    std::cout << "++d3 is " << ++d3 << std::endl;
    std::cout << "  d3 is " << d3;

    std::cout << "\n\nTesting the postfix increment operator:\n"
              << "  d3 is " << d3 << std::endl;
    std::cout << "d3++ is " << d3++ << std::endl;
    std::cout << "  d3 is " << d3 << std::endl;

    return 0;
}
