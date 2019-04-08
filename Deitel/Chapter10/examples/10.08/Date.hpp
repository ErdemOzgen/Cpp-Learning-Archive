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

class Date {
 public:
    static const int monthsPerYear = 12;

    Date(int = 1, int = 1, int = 1900);
    ~Date();

    void print() const;

 private:
    int month;
    int day;
    int year;

    // utility functions
    int checkDay(int) const;
};
