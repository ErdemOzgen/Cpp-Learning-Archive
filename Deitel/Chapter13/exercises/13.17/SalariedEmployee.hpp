/*
 * =====================================================================================
 *
 *       Filename:  SalariedEmployee.hpp
 *
 *    Description:  Fig. 13.11: SalariedEmployee class derived from Employee.
 *
 *        Version:  1.0
 *        Created:  12/08/16 19:30:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
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
