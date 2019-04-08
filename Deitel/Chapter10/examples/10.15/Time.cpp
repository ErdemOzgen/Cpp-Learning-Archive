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

#include <iomanip>
#include <iostream>

Time::Time(int hr, int min, int sec) { setTime(hr, min, sec); }
// SETTERS
Time& Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);

    return *this;  // enables cascading
}
Time& Time::setHour(int h) {
    if (h >= 0 && h < 24)
        hour = h;
    else
        throw std::invalid_argument("hour must be 0-23");

    return *this;  // enables cascading
}
Time& Time::setMinute(int m) {
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw std::invalid_argument("minute must be 0-59");

    return *this;  // enables cascading
}
Time& Time::setSecond(int s) {
    if (s >= 0 && s < 60)
        second = s;
    else
        throw std::invalid_argument("second must be 0-59");

    return *this;  // enables cascading
}
// GETTERS
int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }
// IO OPERATIONS
// print time in universal-time format (HH:MM:SS)
void Time::printUniversal() const {
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
              << std::setw(2) << minute << ":" << std::setw(2) << second;
}
// print Time in standard-time format (HH:MM:SS AM/PM)
void Time::printStandard() const {
    std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
              << std::setfill('0') << std::setw(2) << minute << ":"
              << std::setw(2) << second << (hour < 12 ? " AM" : " PM");
}
