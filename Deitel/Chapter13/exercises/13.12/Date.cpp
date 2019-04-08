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
#include <string>

#include "Date.hpp"

// initialise static member; one classwide copy
const int Date::days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// constructor
Date::Date(int month, int day, int year) { setDate(month, day, year); }
// set month, day, year
void Date::setDate(int mm, int dd, int yy) {
    if (mm >= 1 && mm <= 12) {
        month = mm;
    } else {
        throw std::invalid_argument("Month must be 1-12");
    }

    if (yy >= 1900 && yy <= 2100) {
        year = yy;
    } else {
        throw std::invalid_argument("Year must be >= 1900 and <= 2100");
    }

    // test for leap year
    if ((month == 2 && leapYear(year) && dd >= 1 && dd <= 29) ||
        (dd >= 1 && dd <= days[month])) {
        day = dd;
    } else {
        throw std::invalid_argument(
            "Day is out of range for current month and year.");
    }
}
// overloaded prefix increment operator
Date& Date::operator++() {
    helpIncrement();

    return *this;  // return reference to create lvalue
}
// overloaded postfix incremenet operator; note that the
// dummy integer parameter does not have a parameter name
Date Date::operator++(int) {
    Date temp = *this;  // hold current state of object
    helpIncrement();

    // return unincremented, saved, temporary object
    return temp;
}
// add specified number of days to date
const Date& Date::operator+=(int additionalDays) {
    for (int i = 0; i < additionalDays; ++i) {
        helpIncrement();
    }

    return *this;  // enables cascading
}
// if the year is a leap year return true otherwise false
bool Date::leapYear(int testYear) {
    return (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0));
}
// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay) const {
    if (month == 2 && leapYear(year)) {
        return testDay == 29;  // last day in Feb leap year
    } else {
        return testDay == days[month];
    }
}
// utility function to help increment date
void Date::helpIncrement() {
    if (!endOfMonth(day)) {
        ++day;
    } else {
        if (month < 12) {  // day is end of month and month < 12
            ++month;
            day = 1;
        } else {  // last day of year
            ++year;
            month = 1;
            day = 1;
        }
    }
}
// overloaded output operator
std::ostream& operator<<(std::ostream& output, const Date& d) {
    static std::string monthName[13] = {
        "",        "January",  "February", "Mar.hpp",  "April",
        "May",     "June",     "July",     "August", "September",
        "October", "November", "December"};

    output << monthName[d.month] << ' ' << d.day << ", " << d.year;

    return output;
}
