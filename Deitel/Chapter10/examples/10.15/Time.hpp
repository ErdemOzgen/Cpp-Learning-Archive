
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

class Time {
 public:
    Time(int = 0, int = 0, int = 0);

    // SETTERS
    Time& setTime(int, int, int);
    Time& setHour(int);
    Time& setMinute(int);
    Time& setSecond(int);

    // GETTERS
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // IO OPERATIONS
    void printUniversal() const;
    void printStandard() const;

 private:
    int hour;
    int minute;
    int second;
};
