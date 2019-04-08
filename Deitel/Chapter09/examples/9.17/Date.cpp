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

// date constructor (should do range checking)
Date::Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}
// print date in format mm/dd/yyyy
void Date::print() { std::cout << month << "/" << day << "/" << year; }
