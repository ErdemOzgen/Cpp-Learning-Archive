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
    const double COMMISSION_BASE = 250.0f;
    const double COMMISSION_RATE = 0.057f;
    const double HOURLY_OVERTIME = 1.5f;
    const double PIECE_RATE = 10.0f;

    double managerRate = 0.0f;
    double hourlyRate = 0.0f;
    double weeklySales = 0.0f;
    double hoursWorked = 0.0f;

    int employeeCode = 0;
    int piecesProduced = 0;

 public:
    SalaryCalculator();

    // SETTERS
    void setManagerRate(double);
    void setHourlyRate(double);
    void setWeeklySales(double);
    void setHoursWorked(double);
    void setEmployeeCode(int);
    void setPiecesProduced(int);

    // GETTERS
    double getManagerRate() const { return managerRate; }
    double getHourlyRate() const { return hourlyRate; }
    double getWeeklySales() const { return weeklySales; }
    double getHoursWorked() const { return hoursWorked; }
    int getEmployeeCode() const { return employeeCode; }
    int getPiecesProduced() const { return piecesProduced; }

    void inputSalaries();

    double calculateSalary();

    void reset();
};
