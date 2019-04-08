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
#include <stdexcept>

Date::Date(int mn, int dy, int yr) {
    if (mn > 0 && mn <= monthsPerYear) {
        month = mn;
    } else {
        throw std::invalid_argument("month must be 1-12");
    }

    year = yr;
    day = checkDay(dy);

    // output date object to show when its constructor is called
    std::cout << "Date object constructor for date";
    print();
    std::cout << std::endl;
}
Date::~Date() {
    std::cout << "date object destructor for date ";
    print();
    std::cout << std::endl;
}
// print Date object in the form month/day/year
void Date::print() const { std::cout << month << '/' << day << '/' << year; }
// utility function to confirm proper day value based on month and year;
// handles leap years too
int Date::checkDay(int testDay) const {
    static const int daysPerMonth[monthsPerYear + 1] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // determine whether testDay is valid for specified month
    if (testDay > 0 && testDay <= daysPerMonth[month]) {
        return testDay;
    }

    // february 29 check for leap year
    if (month == 2 && testDay == 29 &&
        (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
        return testDay;
    }

    throw std::invalid_argument("Invalid day for current month and year");
}
