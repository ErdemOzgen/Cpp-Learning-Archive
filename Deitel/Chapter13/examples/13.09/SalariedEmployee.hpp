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

#include "Employee.hpp"

class SalariedEmployee : public Employee {
 public:
    SalariedEmployee(const std::string&, const std::string&, const std::string&,
                     double = 0.0f);

    void setWeeklySalary(double);
    double getWeeklySalary() const;

    // keyword virtual signals intent to override
    virtual double earnings() const;
    virtual void print() const;

 private:
    double weeklySalary;
};
