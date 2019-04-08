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
#include <string>

#include "Employee.hpp"

Employee::Employee(const std::string &fName, const std::string &lName, int mSalary) {
    setFirstName(fName);
    setLastName(lName);
    setMonthlySalary(mSalary);
}

// SETTERS
void Employee::setFirstName(const std::string &fName) { firstName = fName; }
void Employee::setLastName(const std::string &lName) { lastName = lName; }
void Employee::setMonthlySalary(int mSalary) {
    monthlySalary = (mSalary > 0) ? mSalary : 0;
}

// GETTERS
std::string Employee::getFirstName() const { return firstName; }
std::string Employee::getLastName() const { return lastName; }
int Employee::getMonthlySalary() const { return monthlySalary; }
int Employee::calculateSalary(int months) const { return (getMonthlySalary() * months); }
void Employee::giveRaise(int percent) {
    monthlySalary += (monthlySalary / 100) * percent;
}
void Employee::showEmployee() const {
    std::cout << "Name: " << getFirstName() << " " << getLastName()
              << "\nMonthly Salary: " << getMonthlySalary()
              << "\nYearly Salary: " << calculateSalary(12) << std::endl
              << std::endl;
}
