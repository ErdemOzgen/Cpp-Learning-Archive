/*
 * =====================================================================================
 *
 *       Filename:  SalariedEmployee.cpp
 *
 *    Description:  Fig. 13.12: SalariedEmployee class member function
 *                  definitions.
 *
 *        Version:  1.0
 *        Created:  12/08/16 19:36:07
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <string>

#include "SalariedEmployee.hpp"

SalariedEmployee::SalariedEmployee(const std::string& first,
                                   const std::string& last,
                                   const std::string& ssn, double salary)
    : Employee(first, last, ssn) {
    setWeeklySalary(salary);
}
// set salary
void SalariedEmployee::setWeeklySalary(double salary) {
    if (salary >= 0.0f) {
        weeklySalary = salary;
    } else {
        throw std::invalid_argument("Weekly salary must be >= 0.0f");
    }
}
// get salary
double SalariedEmployee::getWeeklySalary() const { return weeklySalary; }
// calculate earnings:
// overwrite pure virtual function earnings in Employee
double SalariedEmployee::earnings() const { return getWeeklySalary(); }
// print SalariedEmployee's information
void SalariedEmployee::print() const {
    std::cout << "salaried employee: ";
    Employee::print();  // reuse abstract base-class print function
    std::cout << "\nweekly salary: " << getWeeklySalary();
}
