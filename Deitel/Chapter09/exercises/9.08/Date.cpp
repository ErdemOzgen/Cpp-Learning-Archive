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

#include <stdexcept>

Date::Date(unsigned int m, unsigned int d, unsigned int y) {
    if (y > 0) {
        year = y;
    } else {
        throw std::invalid_argument("Year must be a positive number");
    }
    if (m > 0 && m <= 12) {
        month = m;
    } else {
        throw std::invalid_argument("Month must be 1-12");
    }

    DAYS_IN_MONTH[2] = (isLeapYear(year) ? LEAP : NO_LEAP);

    if (d > 0 && d <= DAYS_IN_MONTH[month]) {
        day = d;
    } else {
        throw std::invalid_argument("Day must be 0-31");
    }
}

// increment date by 1
void Date::nextDay() {
    if (day < DAYS_IN_MONTH[month]) {
        day++;
    } else {
        day = 1;
        if (month < MONTHS_IN_YEAR) {
            month++;
        } else {
            month = 1;
            year++;

            DAYS_IN_MONTH[2] = (isLeapYear(year) ? LEAP : NO_LEAP);
        }
    }
}

// check whether given year is leap year
bool Date::isLeapYear(unsigned int y) {
    return (y % 4 == 0 || y % 400 == 0 || y % 100 == 0);
}

// print date in format mm/dd/yyyy
void Date::print() { std::cout << month << "/" << day << "/" << year; }

// sensible date printing dd/mm/yyyy
std::ostream& Date::printSensible(std::ostream& out) {
    out << day << "/" << month << "/" << year;
    return out;
}
