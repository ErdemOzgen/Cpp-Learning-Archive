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
#pragma once

#include <iostream>

class DateAndTime {
 public:
    explicit DateAndTime(unsigned int = 1, unsigned int = 1,
                         unsigned int = 2000, unsigned int = 0,
                         unsigned int = 0, unsigned int = 0);

    // SETTERS
    void setTime(unsigned int, unsigned int, unsigned int);
    void setDate(unsigned int, unsigned int, unsigned int);

    void tick();  // increment time by 1 second

    friend std::ostream& operator<<(std::ostream& out, DateAndTime& dt) {
        dt.printUniversal();
    }

    void printUniversal();
    void printStandard();

 private:
    static const size_t MONTHS_IN_YEAR = 12;
    static const size_t NO_LEAP = 28;
    static const size_t LEAP = 29;

    unsigned int DAYS_IN_MONTH[MONTHS_IN_YEAR + 1] =
                    {0,  31, NO_LEAP, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    unsigned int month;
    unsigned int day;
    unsigned int year;
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

    bool isLeapYear(unsigned int);

    void nextDay();  // increment date by 1
};
