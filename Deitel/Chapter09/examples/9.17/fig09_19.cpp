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
    Date date1(7, 4, 2004);
    Date date2;  // defaults to 1/1/200

    std::cout << "date1 = ";
    date1.print();

    std::cout << "\ndate2 = ";
    date2.print();

    date2 = date1;

    std::cout << "\n\nAfter default memberwise assignment, date2 = ";

    date2.print();

    std::cout << std::endl;
    return 0;
}
