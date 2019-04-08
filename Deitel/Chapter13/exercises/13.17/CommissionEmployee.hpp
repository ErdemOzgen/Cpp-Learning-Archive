/*
 * =====================================================================================
 *
 *       Filename:  CommissionEmployee.hpp
 *
 *    Description:  Fig. 13.13: CommissionEmployee class derived from Employee.
 *
 *        Version:  1.0
 *        Created:  12/08/16 19:49:45
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

class CommissionEmployee : public Employee {
 public:
    CommissionEmployee(const std::string&, const std::string&,
                       const std::string&, double = 0.0f, double = 0.0f);

    void setCommissionRate(double);
    double getCommissionRate() const;

    void setGrossSales(double);
    double getGrossSales() const;

    // keyword virtual signals intent to override
    virtual double earnings() const;
    virtual void print() const;

 private:
    double grossSales;
    double commissionRate;
};
