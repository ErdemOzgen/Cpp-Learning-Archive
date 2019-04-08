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

#include <stdexcept>

class Time {
 private:
    int hour;
    int minute;
    int second;

 public:
    Time(int = 0, int = 0, int = 0);
    ;

    void setTime(int, int, int);
    int &badSetHour(int);  // dangerous reference return

    int getHour();
};
