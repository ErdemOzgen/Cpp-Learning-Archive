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
#include <stdexcept>

Time::Time(int hour, int minute, int second) { setTime(hour, minute, second); }
// SETTERS
void Time::setTime(int hour, int minute, int second) {
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}
void Time::setHour(int h) {
    if (h >= 0 && h < 24) {
        hour = h;
    } else {
        throw std::invalid_argument("hour must be 0-23");
    }
}
void Time::setMinute(int m) {
    if (m >= 0 && m < 60) {
        minute = m;
    } else {
        throw std::invalid_argument("minute must be 0-59");
    }
}
void Time::setSecond(int s) {
    if (s >= 0 && s < 60) {
        second = s;
    } else {
        throw std::invalid_argument("second must be 0-59");
    }
}
// GETTERS
int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }
// print time in universal time format HH:HH:SS
void Time::printUniversal() const {
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
              << std::setw(2) << minute << ":" << std::setw(2) << second;
}
// print time in standard time HH:MM:SS AM/PM
void Time::printStandard() const {
    std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
              << std::setfill('0') << std::setw(2) << minute << ":"
              << std::setw(2) << second << (hour < 12 ? " AM" : " PM");
}
