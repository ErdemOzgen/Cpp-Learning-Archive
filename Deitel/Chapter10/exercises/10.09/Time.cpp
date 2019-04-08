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
#include <iostream>

#include "Time.hpp"

Time::Time(int hr, int min, int sec) { setTime(hr, min, sec); }
// SETTERS
Time& Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);

    return *this;  // enables cascading
}
Time& Time::setHour(int h) {
    if (h >= 0 && h < 24) {
        secondsSinceMidnight = h * SECONDS_HOUR;
    } else {
        throw std::invalid_argument("hour must be 0-23");
    }
    return *this;  // enables cascading
}
Time& Time::setMinute(int m) {
    if (m >= 0 && m < 60) {
        secondsSinceMidnight += m * SECONDS_MINUTE;
    } else {
        throw std::invalid_argument("minute must be 0-59");
    }
    return *this;  // enables cascading
}
Time& Time::setSecond(int s) {
    if (s >= 0 && s < 60) {
        secondsSinceMidnight += s;
    } else {
        throw std::invalid_argument("second must be 0-59");
    }
    return *this;  // enables cascading
}
// GETTERS
int Time::getHour() const { return secondsSinceMidnight / SECONDS_HOUR; }
int Time::getMinute() const {
    return (secondsSinceMidnight - (getHour() * SECONDS_HOUR)) / SECONDS_MINUTE;
}
int Time::getSecond() const {
    return secondsSinceMidnight -
           ((getHour() * SECONDS_HOUR) + (getMinute() * SECONDS_MINUTE));
}
// IO OPERATIONS
// print time in universal-time format (HH:MM:SS)
void Time::printUniversal() const {
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setw(2) << getMinute() << ":" << std::setw(2)
              << getSecond();
}
// print Time in standard-time format (HH:MM:SS AM/PM)
void Time::printStandard() const {
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute() << ":"
              << std::setw(2) << getSecond()
              << (getHour() < 12 ? " AM" : " PM");
}
