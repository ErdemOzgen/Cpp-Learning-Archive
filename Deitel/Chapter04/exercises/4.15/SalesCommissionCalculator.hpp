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

class SalesCommissionCalculator {
 private:
    const double COMMISSION = 0.09f;
    const double BASEPAY = 200.0f;

    double weeklySales = 0.0f;
    double weeklyEarnings = 0.0f;

 public:
    SalesCommissionCalculator();
    ~SalesCommissionCalculator();

    // SETTERS
    void setWeeklySales(double);
    void setWeeklyEarnings();

    // GETTERS
    double getWeeklySales() const;
    double getWeeklyEarnings() const;

    void run();
};
