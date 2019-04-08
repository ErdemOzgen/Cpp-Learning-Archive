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
#include "BasePlusCommissionEmployee.hpp"

#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const std::string& first, const std::string& last, const std::string& ssn,
    double sales, double rate, double salary)
    // explicitily call base-class constructor
    : CommissionEmployee(first, last, ssn, sales, rate) {
    setBaseSalary(salary);
}
// base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    if (salary >= 0.0f) {
        baseSalary = salary;
    } else {
        throw std::invalid_argument("Salary must be >= 0.0f");
    }
}
double BasePlusCommissionEmployee::getBaseSalary() const { return baseSalary; }
// earnings
double BasePlusCommissionEmployee::earnings() const {
    CommissionEmployee::earnings();
}
// print
void BasePlusCommissionEmployee::print() const {
    std::cout << "base-salaried ";

    // invoke CommissionEmployee's print function
    CommissionEmployee::print();

    std::cout << "\nbase salary: " << getBaseSalary();
}
