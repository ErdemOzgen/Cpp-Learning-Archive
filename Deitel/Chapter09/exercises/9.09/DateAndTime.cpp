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
#include <iomanip>

#include "DateAndTime.hpp"

DateAndTime::DateAndTime(unsigned int m, unsigned int d, unsigned int y,
                         unsigned int hr, unsigned int min, unsigned int sec) {
    setDate(m, d, y);
    setTime(hr, min, sec);
}

void DateAndTime::setDate(unsigned int m, unsigned int d, unsigned int y) {
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

void DateAndTime::setTime(unsigned int hr, unsigned int min, unsigned int sec) {
    if (hr <= 23) {
        hour = hr;
    } else {
        throw std::invalid_argument("Hour must be 0-23");
    }
    if (min <= 59) {
        minute = min;
    } else {
        throw std::invalid_argument("Minute must be 0-59");
    }
    if (sec <= 59) {
        second = sec;
    } else {
        throw std::invalid_argument("Second must be 0-59");
    }
}

// check if given year is leap year
bool DateAndTime::isLeapYear(unsigned int y) {
    return (y % 4 == 0 || y % 400 == 0 || y % 100 == 0);
}

// increment time by 1 second
void DateAndTime::tick() {
    if (second < 59) {
        second++;
    } else {
        second = 0;
        if (minute < 59) {
            minute++;
        } else {
            minute = 0;
            if (hour < 23) {
                hour++;
            } else {
                hour = 0;
                minute = 0;
                second = 0;

                nextDay();
            }
        }
    }
}

// increment date by 1
void DateAndTime::nextDay() {
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

// print Time in universal-time format (HH:MM:SS)
void DateAndTime::printUniversal() {
    std::cout << day << "/" << month << "/" << year << " " << std::setfill('0')
              << std::setw(2) << hour << ":" << std::setw(2) << minute << ":"
              << std::setw(2) << second;
}

// print Time in standard-time format (H:MM:SS AM PM)
void DateAndTime::printStandard() {
    std::cout << day << "/" << month << "/" << year << " "
              << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
              << std::setfill('0') << std::setw(2) << minute << ":"
              << std::setw(2) << second << (hour < 12 ? " AM" : " PM");
}
