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
 private:
    int month = 1;
    int day = 1;
    int year = 1900;

 public:
    Date(int, int, int);

    // SETTERS
    void setMonth(int);
    void setDay(int);
    void setYear(int);

    // GETTERS
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    void displayDate() const;
};
