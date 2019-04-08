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

class Date {
 public:
    explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 2000);

    void nextDay();  // increment date by 1

    void print();

    friend std::ostream& operator<<(std::ostream& out, Date& d) {
        return d.printSensible(out);
    }

 private:
    static const size_t MONTHS_IN_YEAR = 12;
    static const size_t NO_LEAP = 28;
    static const size_t LEAP = 29;

    unsigned int DAYS_IN_MONTH[MONTHS_IN_YEAR + 1] = {0,  31, NO_LEAP, 31, 30, 31, 30,
                                             31, 31, 30,      31, 30, 31};

    unsigned int month;
    unsigned int day;
    unsigned int year;

    bool isLeapYear(unsigned int);

    std::ostream& printSensible(std::ostream&);
};
