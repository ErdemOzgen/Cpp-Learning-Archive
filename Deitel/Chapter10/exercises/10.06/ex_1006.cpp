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

#include "Date.hpp"

int main(int argc, const char *argv[]) {
    Date d1;
    Date d2("February", 14, 1952);

    d1.printDayYear();
    printf("\n");
    d1.printShort();
    printf("\n");
    d1.printLong();
    printf("\n\n");

    d2.printDayYear();
    printf("\n");
    d2.printShort();
    printf("\n");
    d2.printLong();
    std::cout << std::endl;

    return 0;
}
