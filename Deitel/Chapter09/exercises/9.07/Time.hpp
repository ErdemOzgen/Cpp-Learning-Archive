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
    explicit Time(int = 0, int = 0, int = 0);

    // SETTERS
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // GETTERS
    int getHour();
    int getMinute();
    int getSecond();

    void tick();  // increment time by 1 second

    void printUniversal();
    void printStandard();

 private:
    int hour;
    int minute;
    int second;
};
