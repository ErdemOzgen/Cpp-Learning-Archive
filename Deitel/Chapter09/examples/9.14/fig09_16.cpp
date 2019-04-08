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

    // initialise hourRef with the reference returned by badSethour
    int &hourRef = t.badSetHour(20);

    std::cout << "Valid hour before modification: " << hourRef;
    hourRef = 30;  // user hourRef to set invalid value in Time object t
    std::cout << "\nInvalid hour after modification: " << t.getHour();

    // Dangerous: Function call that returns
    // a reference can be used as an lvalue!
    t.badSetHour(12) = 74;

    std::cout << "\n\n********************************\n"
              << "POOR PROGRAMMING PRACTISE!!!!!!!\n"
              << "t.badSetHour(12) as an lvalue, invalid hour: " << t.getHour()
              << "\n**********************************" << std::endl;
    return 0;
}
