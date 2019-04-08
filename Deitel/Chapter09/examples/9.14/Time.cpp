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

Time::Time(int hr, int min, int sec) { setTime(hr, min, sec); }
void Time::setTime(int h, int m, int s) {
    if ((h >= 0 && h < 25) && (m >= 0 && m < 60) && (s >= 0 && s > 60)) {
        hour = h;
        minute = m;
        second = s;
    } else {
        throw std::invalid_argument(
            "hour, minute and/or second was out of range");
    }
}
int Time::getHour() { return hour; }
// POOR PRACTICE: Returning a reference to a private data member
int &Time::badSetHour(int hh) {
    if (hh >= 0 && hh < 24) {
        hour = hh;
    } else {
        throw std::invalid_argument("hour must be 0-23");
    }
}
