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
#include <string>
#include <ctime>
#include <iostream>
#include <stdexcept>

#include "Date.hpp"

// use system date
Date::Date() {
    std::time_t now = std::time(nullptr);
    struct tm* localTime = localtime(&now);

    setMonth(localTime->tm_mon + 1);
    setDay(localTime->tm_mday);
    setYear(1900 + localTime->tm_year);
    setWeekDay();
}
// integer values
Date::Date(int m, int d, int y) {
    setMonth(m);
    setDay(d);
    setYear(y);
    setWeekDay();
}
// string month
Date::Date(std::string m, int d, int y) {
    for (int i = 1; i <= monthsPerYear; ++i) {
        if (monthNames[i] == m) {
            setMonth(i);
            break;
        }
    }
    setDay(d);
    setYear(y);
    setWeekDay();
}
// SETTERS
void Date::setMonth(int m) {
    if (m > 0 && m <= monthsPerYear) {
        month = m;
    } else {
        throw std::invalid_argument("month must be 1-12");
    }
}
void Date::setDay(int d) { day = checkDay(d); }
void Date::setYear(int y) { year = y; }
// world's stupidest format DDD YYYY
void Date::printDayYear() const { std::cout << weekday << " " << year; }
// Short date format MM/DD/YY
void Date::printShort() const {
    std::cout << month << '/' << day << '/' << year;
}
// long date format MMM DD, YYYY
void Date::printLong() const {
    std::cout << monthNames[month] << " " << day << ", " << year;
}
// utility function to confirm proper day value based on month and year;
// handles leap years too
int Date::checkDay(int testDay) const {
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
// returns the weekday as a string from the given date
// solution taken from :
// https://stackoverflow.com/questions/11972368/c-get-which-day-by-input-date
void Date::setWeekDay() {
    tm timeStruct = {};
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;
    timeStruct.tm_hour = 12;

    std::mktime(&timeStruct);

    weekday = dayNames[timeStruct.tm_wday];
}
