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

class SalaryCalculator {
 private:
    const double BASE_HOURS = 40.0f;

    double hoursWorked = 0.0f;
    double hourlyRate = 0.0f;

 public:
    SalaryCalculator();
    ~SalaryCalculator();

    // SETTERS
    void setHoursWorked(double);
    void setHourlyRate(double);

    // GETTERS
    double getHoursWorked() const;
    double getHourlyRate() const;
    double getSalary() const;

    void run();
};
