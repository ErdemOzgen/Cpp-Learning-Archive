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
    Time t1(13, 25, 59);
    Time t2(7, 51, 12);

    t1.printUniversal();
    printf("\n");
    t2.printUniversal();
    printf("\n");
    t1.printStandard();
    printf("\n");
    t2.printStandard();

    std::cout << std::endl;
    return 0;
}
